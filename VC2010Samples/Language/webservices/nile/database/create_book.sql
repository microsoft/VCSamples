set nocount on
delete from products
go

declare @i integer
select @i = 1
declare @subjectID integer
select @subjectID = 1

declare @BookTitle varchar(50)
declare @Author varchar(50)
declare @Price money
declare @Retail money
declare @ISBN varchar(50)
declare @QuantityOnHand integer
declare @SpecialItem binary
declare @mod integer

set @mod = 1
select @SpecialItem = 0x01

while (@i <= 1000)
begin
	if (@i % 101 = 0) set @mod = @mod+1
	select @BookTitle = rtrim('Book ' + convert(varchar(10), @i) + ' Title')
	select @Author = rtrim('Author' + convert(varchar(10), @mod))
	select @ISBN = rtrim('ISBN_Book' + convert(varchar(10), @i))
	select @Price = convert(money, ((@i % 4) +1)*5)
	select @Retail = convert(money, @Price*1.5)
	if (@i = 11) select @specialItem = 0x00

	exec Product_Insert @i, @subjectID, @BookTitle, @Author, @Price, @Retail, @ISBN, 
		100, @SpecialItem
	

	if @i % 1000 = 0 print @i

	select @i = @i + 1
	select @subjectID = @subjectID + 1
	If @subjectID = 22 select @subjectID = 1 

end

