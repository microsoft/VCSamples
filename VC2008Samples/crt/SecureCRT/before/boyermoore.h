#define ALPHABETSIZE	256

class BoyerMoore
{
public:
	BoyerMoore(char *);
	~BoyerMoore();
	char *Match(char *);
	const char *Pattern();
	
private:
	void compute_last_occurence();
	void compute_prefix(int *, char *);
	void compute_good_suffix();
	
private:
	char *m_pattern;
	int m_patternLen;
	int m_lastOccurence[ALPHABETSIZE];
	int *m_prefix, *m_suffix, *m_revPrefix;
};
