//Kamil Wisniewski
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct wartosci
{
	char znak;
	int wartosc;
};




class kr
{
private:
	std::wstring tekst;
	std::wstring wzorzec;
	std::vector<int>miejsce;
	int siz;
	int hashwzr;
	int h = 1;
	int q = 7651;

	std::wstring temp;
public:

	void setsize(int sizee);
	long long int conv(std::wstring pat);
	void szukaj();
	void settekst(std::wstring teks);
	void sethash(int hsh);
	void setwzorzec(std::wstring wz);
	long long int conv2(int i, long long int p);
	void nw();


	void wypiszmiejsca();
};

void kr::setsize(int sizee)
{
	siz = sizee;
}


long long int kr::conv2(int i, long long int p)
{
	p = (256 * (p - tekst[i] * h) + tekst[i + siz]) % q;

	if (p < 0)
	{
		p = (p + q);
	}
	return p;
}


long long int kr::conv(std::wstring pat)
{
	long long int p = 0;
	for (int i = 0; i < siz; ++i)
	{
		p = p * 256;
		p = p + pat[i];
		p = p % q;
	}



	return p;

}

void kr::setwzorzec(std::wstring wz)
{
	wzorzec = wz;
}


void kr::szukaj()
{
	int j;
	int pm;
	int a = siz - 1;
	int t2;
	temp.clear();
	for (int n = 0; n < siz; n++)
	{
		temp = temp + tekst[n];
	}
	pm = conv(temp);
	if (pm == hashwzr)
	{

		if (temp == wzorzec)
		{
			miejsce.push_back(0);
		}
	}

	temp.clear();


	for (int i = 0; i < tekst.size() - a; ++i)
	{


		pm = conv2(i, pm);

		if (pm == hashwzr)
		{
			for (j = 0; j < siz; j++)
			{

				if (tekst[i + j + 1] != wzorzec[j])
					break;
			}
			if (j == siz)
			{
				miejsce.push_back(i + 1);
			}
		}
	}
}


void kr::settekst(std::wstring tks)
{
	tekst = tks;
}

void kr::sethash(int hsh)
{
	hashwzr = hsh;
}

void kr::wypiszmiejsca()
{
	for (int i = 0; i < miejsce.size(); ++i)
	{
		std::cout << miejsce[i] << " ";
	}
	std::cout << std::endl;
}


void kr::nw()
{

	for (int i = 0; i < siz - 1; i++)
	{
		h = (h * 256) % q;
	}
}

int main()
{
	int ilosc;
	std::cin >> ilosc;
	for (int i = 0; i < ilosc; i++)
	{
		kr k;

		std::wstring tempppp;
		std::wstring tekst;

		tekst.clear();

		std::wstring wzorzec;
		std::wstring nazwapliku;

		std::wcin >> nazwapliku;
		std::getline(std::wcin, tempppp);
		std::getline(std::wcin, wzorzec);

		int siz = wzorzec.size();

		k.setwzorzec(wzorzec);

		std::wfstream plik;
		plik.open(nazwapliku, std::ios::in);




		if (plik.good() == true)
		{


			std::getline(plik, tekst);

			k.setsize(siz);

			k.settekst(tekst);

			k.nw();
			int hashwzor = 0;
			hashwzor = k.conv(wzorzec);
			k.sethash(hashwzor);

			k.szukaj();

			k.wypiszmiejsca();
		}
		plik.close();
	}

	return 0;
}