void string_copy(char* pd, char* ps)
{
	char t[32];
	for (; *pd++ = *ps++;);
}
int len_(const char* s)
{
	int len = 0;
	while (s[len] != 0)len++;
	return len;
}
int compare_(const char* s, const char* t)
{
	const char* p, * d;
	for (p = s, d = t; (*d == *p) && *p; d++, p++);
	return (*p - *d);

}