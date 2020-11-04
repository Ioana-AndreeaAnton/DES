#include<iostream>
#include<fstream>
#include<bitset>
#include<cmath>
#include<string>
#include<sstream>
#include<time.h>

using namespace std;

/*VARIABILE GLOBALE*/

/*PC-1*/
int pc1[56] = {
57,49,41,33,25,17,9,
1,58,50,42,34,26,18,
10,2,59,51,43,35,27,
19,11,3,60,52,44,36,
63,55,47,39,31,23,15,
7,62,54,46,38,30,22,
14,6,61,53,45,37,29,
21,13,5,28,20,12,4
};


/*PC-2*/
int pc2[48] = {
14,17,11,24,1,5,
3,28,15,6,21,10,
23,19,12,4,26,8,
16,7,27,20,13,2,
41,52,31,37,47,55,
30,40,51,45,33,48,
44,49,39,56,34,53,
46,42,50,36,29,32
};

/*Permutarea Initiala*/
int PI[64] = {
58,50,42,34,26,18,10,2,
60,52,44,36,28,20,12,4,
62,54,46,38,30,22,14,6,
64,56,48,40,32,24,16,8,
57,49,41,33,25,17,9,1,
59,51,43,35,27,19,11,3,
61,53,45,37,29,21,13,5,
63,55,47,39,31,23,15,7
};

/*Expansiune*/
int E[48] = {
32,1,2,3,4,5,4,5,
6,7,8,9,8,9,10,11,
12,13,12,13,14,15,16,17,
16,17,18,19,20,21,20,21,
22,23,24,25,24,25,26,27,
28,29,28,29,30,31,32,1
};

/*Substitutie*/
int S1[4][16] = {
	14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
	0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
	4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
	15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
};

int S2[4][16] =
{
	15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
	3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
	0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
	13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
};

int S3[4][16] =
{
	10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
	13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
	13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
	1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
};

int S4[4][16] =
{
	 7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
	 13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
	 10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
	 3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
};

int S5[4][16] =
{
	2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
	14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
	4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
	11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
};

int S6[4][16] =
{
	12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
	10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
	9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
	4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
};

int S7[4][16] =
{
	 4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
	 13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
	 1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
	 6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
};

int S8[4][16] =
{
	13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
	1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
	7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
	2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
};

/*Permutarea P*/
int P[32] = {
16,7,20,21,29,12,28,17,
1,15,23,26,5,18,31,10,
2,8,24,14,32,27,3,9,
19,13,30,6,22,11,4,25
};

/*Inversa Permutarii Initiale*/
int invPI[64] = {
40,8,48,16,56,24,64,32,
39,7,47,15,55,23,63,31,
38,6,46,14,54,22,62,30,
37,5,45,13,53,21,61,29,
36,4,44,12,52,20,60,28,
35,3,43,11,51,19,59,27,
34,2,42,10,50,18,58,26,
33,1,41,9,49,17,57,25
};

string key_valid() {
	int* cheie;
	cheie = new int[64];
	srand(time(NULL));
	int sum = 0;
	string valid_key = "";
	for (int i = 0; i < 64; i++) {
		if (i % 8 == 7) {
			if (sum % 2 == 0) {
				cheie[i] = 0;

			}
			else {
				cheie[i] = 1;
			}
			sum = 0;
		}
		else {
			cheie[i] = rand() % 2;
			sum = sum + cheie[i];
		}
	}
	
	for (int i = 0; i < 64; i++) valid_key = valid_key + to_string(cheie[i]);
	return valid_key;

}



/*functie de conversie a unui text citit in binar*/
string text_to_bin(string text) {
	int nrBinar[100];
	char c;
	string msg = "";
	for (int h = 0; h < text.length(); h++) {
		int i = 0;
		string numar = "";
		bitset<8> bitnr;

		int n = int(text[h]);
		while (n > 0) {
			nrBinar[i] = n % 2;
			n = n / 2;
			i++;
		}
		for (int j = i - 1; j >= 0; j--)
			numar = numar + to_string(nrBinar[j]);

		bitnr = bitset<8>(numar);
		msg = msg + bitnr.to_string();
	}
	return msg;


}

/*functia permutare*/
template <size_t N1, size_t N2>
void permutare(bitset<N1> bloc_in, int P[], bitset<N2>& bloc_fin) {
	for (int i = 0; i < N2; i++) {
		bloc_fin[N2 - 1 - i] = bloc_in[N1 - P[i]];
	}
}

/*Impartirea unui bloc de lungime N, in doua blocuri de lungimi egale*/
template<size_t N>
void impartire_bloc(bitset<N> bloc_in, bitset<N / 2>& bloc_nou1, bitset<N / 2>& bloc_nou2) {
	for (int i = 0; i < N / 2; i++) {
		bloc_nou2[i] = bloc_in[i];
		bloc_nou1[i] = bloc_in[i + N / 2];
	}
}

/*Concatenarea a doua bitseturi*/
template <size_t N1, size_t N2 >
bitset <N1 + N2> concatenare_bitset(const bitset <N1>& b1, const bitset <N2>& b2) {
	string s1 = b1.to_string();
	string s2 = b2.to_string();
	return bitset <N1 + N2>(s1 + s2);
}

/*rotire la stanga*/
template<size_t N>
bitset<N> rotire_st(bitset<N> bloc, int nr) {
	return bloc << nr | bloc >> (N - nr);
}

/*Generare subchei pentru criptare*/
/*dintr-o cheie key de 64 biti, obtinem un vector de 16 subchei, fiecare de 48 biti*/
void creare_subchei(bitset<64> key, bitset<48> subchei[16]) {
	//bitii cheii key sunt permutati folosind permutarea PC-1 si rezultatul este memorat in key56
	bitset<56> key56;
	permutare(key, pc1, key56);

	//impartim rezultatul key56 in doua parti egale
	bitset<28> C0;
	bitset<28> D0;
	impartire_bloc(key56, C0, D0);

	bitset<28> C[17];
	bitset<28> D[17];
	for (int i = 0; i <= 16; i++) {
		if (i == 0) {
			C[0] = C0;
			D[0] = D0;
		}
		else if (i == 1 || i == 2 || i == 9 || i == 16) {//aplicam regula de shiftare
			C[i] = rotire_st(C[i - 1], 1);//shiftam la stanga cu o pozitie
			D[i] = rotire_st(D[i - 1], 1);//shiftam la stnga cu o pozitie
		}
		else {//if (i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16) {
			C[i] = rotire_st(C[i - 1], 2);//shiftam la stanga cu doua pozitii 
			D[i] = rotire_st(D[i - 1], 2);//shiftam la stanga cu doua pozitii
		}
	}

	bitset<56> cheie[16];
	for (int i = 0; i < 16; i++) {
		cheie[i] = concatenare_bitset(C[i + 1], D[i + 1]);//concatenam pentru a forma  cele 16 perechi CnDn
	}

	for (int i = 0; i < 16; i++) {
		permutare(cheie[i], pc2, subchei[i]); //fiecare cheie o permutam cu pc2, obtinand o subcheie 
	}
}


/*Generare subchei intoarse pentru decriptare*/
void chei_intoarse(bitset<48> chei[16], bitset<48> chei_[16]) {
	int start = 0;
	int end = 15;
	bitset<48> aux;
	while (start < end) {
		aux = chei[start];
		chei[start] = chei[end];
		chei[end] = aux;
		start++;
		end--;
	}

	for (int i = 0; i < 16; i++) {
		chei_[i] = chei[i];
	}
}

/*XOR*/
template<size_t N>
bitset<N> XOR(bitset<N> bloc1, bitset<N> bloc2) {
	bitset<N> bloc;
	for (int i = 0; i < N; i++) {
		bloc[i] = bloc1[i] ^ bloc2[i];
	}
	return bloc;
}

/*Substitutia S*/
int S_fc(bitset<6> b, int i) {
	int r, d;
	r = b[5] * 2 + b[0];
	d = b[4] * 8 + b[3] * 4 + b[2] * 2 + b[1];
	if (i == 0)
		return S1[r][d]; //cautam rezultatul in S1
	else if (i == 1)
		return S2[r][d]; //cautam rezultatul in S2
	else if (i == 2)
		return S3[r][d]; //cautam rezultatul in S3
	else if (i == 3)
		return S4[r][d]; //cautam rezultatul in S4
	else if (i == 4)
		return S5[r][d]; //cautam rezultatul in S5
	else if (i == 5)
		return S6[r][d]; //cautam rezultatul in S6
	else if (i == 6)
		return S7[r][d]; //cautam rezultatul in S7
	else if (i == 7)
		return S8[r][d]; //cautam rezultatul in S8
	else return -1;
}


/*transforma un grup de 6 biti intr-un grup de 4 biti*/
string str_fc(bitset<6> bitbloc, int i) {
	int b = S_fc(bitbloc, i);
	bitset<4> bloc(b);
	string s = bloc.to_string();
	return s;
}

/*Transformarea unui bloc de 48 biti intr-un bloc de 32 biti*/
bitset<32> Sbox(bitset<48> bloc) {
	string bloc48 = bloc.to_string();
	string B[8];
	for (int i = 0; i < 8; i++) {
		B[i] = bloc48.substr(i * 6, 6);
	}

	bitset<6> bloc6[8];
	for (int i = 0; i < 8; i++) {
		bloc6[i] = bitset<6>(B[i]);
	}

	//transformam fiecare grup de 6 biti in grupuri de 4 biti dupa regula
	string b[8];
	for (int i = 0; i < 8; i++) {
		b[i] = str_fc(bloc6[i], i);
	}

	//concatenam stringurile
	string str = "";
	for (int i = 0; i < 8; i++) {
		str = str + b[i];
	}

	bitset<32> bit32(str);

	return bit32;
}

/*functia f=P[S(E(Rn-1)(xor)Kn )]*/
bitset<32> functia_f(bitset<32> Rn, bitset<48>Kn) {
	//expansiunea
	bitset<48> expansiune;
	permutare(Rn, E, expansiune);

	//xor cu Kn
	bitset<48> xor_rez;
	xor_rez = XOR(expansiune, Kn);

	//substitutia
	bitset<32> S_rez;
	S_rez = Sbox(xor_rez);

	//permutarea
	bitset<32> P32_rez;
	permutare(S_rez, P, P32_rez);
	return P32_rez;
}

bitset<64> DES_criptare_bloc64(bitset<64> mesaj, bitset<64> key) {
	/*permutare initiala*/
	bitset<64> permutare_init;
	permutare(mesaj, PI, permutare_init);

	/*creare subchei*/
	bitset<48> subchei[16];
	creare_subchei(key, subchei);

	/*impartire bloc*/
	bitset<32> L0;
	bitset<32> R0;
	impartire_bloc(permutare_init, L0, R0);

	bitset<32> L[16];
	bitset<32> R[16];
	bitset<32> aux;
	for (int i = 0; i < 16; i++) {
		if (i == 0) {
			L[0] = R0;
			aux = functia_f(R0, subchei[0]);
			R[0] = XOR(L0, aux);
		}
		else {
			L[i] = R[i - 1];
			aux = functia_f(R[i - 1], subchei[i]);
			R[i] = XOR(L[i - 1], aux);
		}
	}

	/*schimbam ordinea, concatenam si aplicam permutarea inversa*/
	bitset<32> auxiliar;
	aux = L[15];
	L[15] = R[15];
	R[15] = aux;
	bitset<64> concatenare;
	concatenare = concatenare_bitset(L[15], R[15]);
	bitset<64> final_msg;
	permutare(concatenare, invPI, final_msg);
	return final_msg;

}


/*functia de criptare*/
string DES_encryption(string msg, bitset<64> key) {

	//in cazul in care lungimea bitsetului nu este modulo 64, adaugam 0
	while (msg.length() % 64 != 0) {
		msg = "0" + msg;
	}


	bitset<64> bloc64[100];

	for (int i = 0; i < msg.length() / 64; i++) {
		bloc64[i] = bitset<64>(msg.substr(i * 64, 64));
	}
	string msg_criptat = "";
	bitset<64> mesaj_criptat[100];
	for (int i = 0; i < msg.length() / 64; i++) {
		mesaj_criptat[i] = DES_criptare_bloc64(bloc64[i], key);
		msg_criptat = msg_criptat + mesaj_criptat[i].to_string();
	}

	return msg_criptat;
}


bitset<64> DES_decriptare_bloc64(bitset<64> mesaj, bitset<64> key) {
	/*permutare initiala*/
	bitset<64> permutare_init;
	permutare(mesaj, PI, permutare_init);

	/*creare subchei*/
	bitset<48> subchei[16];
	creare_subchei(key, subchei);

	/*creare subchei intoarse*/
	bitset<48> subchei_[16];
	chei_intoarse(subchei, subchei_);

	/*impartire bloc*/
	bitset<32> L0;
	bitset<32> R0;
	impartire_bloc(permutare_init, L0, R0);

	bitset<32> L[16];
	bitset<32> R[16];
	bitset<32> aux;
	for (int i = 0; i < 16; i++) {
		if (i == 0) {
			L[0] = R0;
			aux = functia_f(R0, subchei_[0]);
			R[0] = XOR(L0, aux);
		}
		else {
			L[i] = R[i - 1];
			aux = functia_f(R[i - 1], subchei_[i]);
			R[i] = XOR(L[i - 1], aux);
		}
	}

	/*schimbam ordinea, concatenam si aplicam permutarea inversa*/
	bitset<32> auxiliar;
	aux = L[15];
	L[15] = R[15];
	R[15] = aux;
	bitset<64> concatenare;
	concatenare = concatenare_bitset(L[15], R[15]);
	bitset<64> final_msg;
	permutare(concatenare, invPI, final_msg);
	return final_msg;

}


string DES_decryption(string msg, bitset<64> key) {


	/*//in cazul in care lungimea bitsetului nu este modulo 64, adaugam 0
	while (msg.length() % 64 != 0) {
		msg = "0" + msg;
	}
	*/

	bitset<64> bloc64[100];

	for (int i = 0; i < msg.length() / 64; i++) {
		bloc64[i] = bitset<64>(msg.substr(i * 64, 64));
	}
	string msg_criptat = "";
	bitset<64> mesaj_criptat[100];
	for (int i = 0; i < msg.length() / 64; i++) {
		mesaj_criptat[i] = DES_decriptare_bloc64(bloc64[i], key);
		msg_criptat = msg_criptat + mesaj_criptat[i].to_string();
	}

	return msg_criptat;
}

/*convertim un numar scris in binar */
string binar_to_text(string text) {
	string impartire[100];
	for (int i = 0; i < text.length() / 8; i++) {
		impartire[i] = text.substr(i * 8, 8);
	}
	bitset<8> bit_vector[100];
	int conversie[100];
	string mesaj = "";
	for (int i = 0; i < text.length() / 8; i++) {
		bit_vector[i] = bitset<8>(impartire[i]);
		conversie[i] = bit_vector[i].to_ullong();
		mesaj = mesaj + char(conversie[i]);
	}
	return mesaj;
}



int main() {
	ifstream in("sursa.txt");
	if (!in.good())
		perror("Fisier inexistent");

	string mesaj = "";
	char ch;
	while (in >> noskipws >> ch) {
		mesaj = mesaj + ch;
	}

	cout << "Mesajul in clar: " << endl;
	cout << mesaj << endl;

	string str = text_to_bin(mesaj);
	cout << "Mesajul in clar scris in binar: " << endl;
	cout<< str << endl;
	cout << endl;

	string cheie= key_valid();
	cout << "Cheie valida: " << cheie << endl;
	
	bitset<64> key(cheie);
	
	
	
	
	string msg_criptat = DES_encryption(str, key);
	cout << "Mesajul criptat scris in binar: " << endl;
	cout<< msg_criptat << endl;
	cout << endl;
	string msg_car = binar_to_text(msg_criptat);
	cout << "Mesajul criptat in caractere: " << endl;
	cout<< msg_car << endl;


	string msg_decriptat = DES_decryption(msg_criptat, key);

	//scapam de 0-urile in plus
	int f = msg_decriptat.find('1');
	string msg_dec = msg_decriptat.substr(f);

	while (msg_dec.length() % 8 != 0) {
		msg_dec = "0" + msg_dec;
	}

	cout << endl;
	cout << "Mesajul decriptat scris in binar: " << endl;
	cout<< msg_dec << endl;
	cout << endl;
	string msg_crip = binar_to_text(msg_dec);
	cout << "Mesajul decriptat in caractere: " << endl;
	cout<< msg_crip << endl;

	


	system("pause");
	return 0;
}