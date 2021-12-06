#include <iostream>
#include <valarray>
#include <fstream>
using namespace std;
#define d2valarray valarray<valarray<double> >

float det(d2valarray matris)
{ // UCGEN MATRIS YONTEMI ILE HESAPLAMA

	int n=matris.size();
	float sonuc,oran;
	
	if(n==1){ sonuc=matris[0][0]; }
	
	else if(n==2)
	{
		sonuc = (matris[0][0]*matris[1][1])-(matris[1][0]*matris[0][1]);
	}
	
	else
	{
	
		for (int i=0;i<n;i++)
		{
			for (int k=0;k<n;k++)
			{
				if(k>i)
				{
					oran = (-1)*matris[k][i]/matris[i][i];
			
					for(int j=0;j<n;j++)
					{
						matris[k][j]+=(oran*matris[i][j] );
					}
				}
			}
		}
		sonuc=1.0;
	
		for(int i=0;i<n;i++){ sonuc*=matris[i][i]; }
	}

return (sonuc);
}


void Xmatris(d2valarray A,valarray<double> B,valarray<double> &X)
{
	int n=A.size();
	
	valarray<d2valarray> Aaltmat(n);
	d2valarray G(n);
	
	for (int i=0;i<n;i++)
	{
		
		for(int k=0;k<n;k++)G[k].resize(n);
		
		G=A;
		
		for(int j=0;j<n;j++)
		{
			G[j][i]=B[j];
			
		}
			Aaltmat[i]=G;
	}
		
	
	if (det(A)==0){cout<<"\ndeterminant A sifira esit cramer yontemi kullanilamaz.";}
	
	else
	{
		for(int i=0;i<n;i++){ X[i]=det(Aaltmat[i])/det(A); } 
	}
	
}


int main()
{
	int n;
	cout<<"cramer yontemi [ A.X=B]\n";
	cout<<"A matrisinin satir ve sutun miktarini giriniz. (nxn)\n";
	
	cin>> n;
	
	d2valarray A(n);
	for(int k=0;k<n;k++)A[k].resize(n);
	
	cout<<"A matrisinin elemanlarini giriniz.\n";
	float aij;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++){cin>> aij; A[i][j]=aij;} 
	}

	valarray<double> B(n);
	float bi;
	
	cout<<"B matrisinin elemanlarini giriniz.\n";
	
	for(int i=0;i<n;i++){cin>> bi; B[i]=bi;}
	
	valarray<double> X(n);
	
	Xmatris(A,B,X);
	
	ofstream myfile;
	myfile.open("ciktilar.txt");
	myfile<<"A matrisi \n";
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			myfile<< A[i][j]<< " ";
		}
		myfile << " \n";
	}
	myfile<<"B matrisi  \n";
	
	for (int i=0;i<n;i++)
	{
		myfile<< B[i]<< " "<<endl;
	}

	myfile<<"X matrisi  \n";
	
	for (int i=0;i<n;i++)
	{
		myfile<< X[i]<< " "<<endl;
	}
	
	
	return 0;
}
