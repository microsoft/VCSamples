using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Interop;

namespace WpfSample
{
    public class GotFocusEventArgs : EventArgs
    {
        private IntPtr _hwndLostFocus;

        public GotFocusEventArgs(IntPtr hwndLostFocus)
        {
            _hwndLostFocus = hwndLostFocus;
        }
        public IntPtr HwndLostFocus
        {
            get { return _hwndLostFocus; }
        }
    }

    public class WpfElementHost : IDisposable
    {
        public WpfElementHost()
        {
            _elementContainer = new WpfElementContainer(this);
            _decorator = new AdornerDecorator();
            _decorator.Child = _elementContainer;
            FocusManager.SetIsFocusScope(_decorator, true);
        }

        public IntPtr Create(int classStyle, int style, int exStyle, int x, int y, int width, int height,
            string name, IntPtr parent)
        {
            HwndSourceParameters parameters = new HwndSourceParameters(name, width, height);
            parameters.WindowClassStyle = classStyle;
            parameters.WindowStyle = style;
            parameters.ExtendedWindowStyle = exStyle;
            parameters.SetPosition(x, y);
            parameters.ParentWindow = parent;
            parameters.HwndSourceHook = HwndSourceHook;
            return Create(parameters);
        }

        private IntPtr Create(HwndSourceParameters parameters)
        {
            DisposeHWndSource();
            _hwndSource = new HwndSource(parameters);
            _hwndSource.RootVisual = _decorator;
            (_hwndSource as IKeyboardInputSink).KeyboardInputSite = (ElementContainerInternal as IKeyboardInputSite);
            return _hwndSource.Handle;
        }

        private IntPtr HwndSourceHook(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
        {
            switch (msg)
            {
                case NativeMethods.WM_SETFOCUS:
                    OnGotFocus(new GotFocusEventArgs(wParam));
                    break;
            }

            return IntPtr.Zero;
        }

        protected virtual void OnGotFocus(GotFocusEventArgs args)
        {
            EventHandler<GotFocusEventArgs> gotFocusEvent = GotFocus;
            if (gotFocusEvent != null)
                gotFocusEvent(this, args);
        }

        public event EventHandler<GotFocusEventArgs> GotFocus;

        private UIElement _element;
        public UIElement Element
        {
            get
            {
                return _element;
            }
            set
            {
                _element = value;
                ElementContainerInternal.Children.Clear();
                if (_element != null)
                {
                    ElementContainerInternal.Children.Add(_element);
                }
            }
        }

        private bool _disposed = false;
        public void Dispose()
        {
            if (!_disposed)
            {
                DisposeHWndSource();

                IDisposable disposableElement = Element as IDisposable;
                if (disposableElement != null)
                    disposableElement.Dispose();

                _disposed = true;
            }
        }

        private void DisposeHWndSource()
        {
            if (_hwndSource != null)
            {
                (_hwndSource as IKeyboardInputSink).KeyboardInputSite = null;
                _hwndSource.Dispose();
                _hwndSource = null;
            }
        }
        
        private HwndSource _hwndSource;
        internal HwndSource HwndSource
        {
            get { return _hwndSource; }
        }

        public IKeyboardInputSink KeyboardInputSink
        {
            get
            {
                return (IKeyboardInputSink)_hwndSource;
            }
        }

        private AdornerDecorator _decorator;

        private WpfElementContainer _elementContainer;
        internal WpfElementContainer ElementContainerInternal
        {
            get
            {
                return _elementContainer;
            }
        }
        public Panel ElementContainer
        {
            get { return ElementContainerInternal; }
        }
    }

    internal class WpfElementContainer : DockPanel, IKeyboardInputSite
    {
        private WpfElementHost _elementHost;

        internal WpfElementContainer(WpfElementHost elementHost)
        {
            _elementHost = elementHost;
        }

        #region IKeyboardInputSite
        public void Unregister()
        {
        }

        public bool OnNoMoreTabStops(TraversalRequest request)
        {
            // TODO: Allow the ElementHost's container to handle Tab/Arrow navigation
            return false;
        }

        public IKeyboardInputSink Sink
        {
            get
            {
                return (_elementHost.HwndSource as IKeyboardInputSink);
            }
        }
        #endregion IKeyboardInputSite
    }

}
