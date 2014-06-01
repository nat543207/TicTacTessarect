/*
 * MagicSquareGenerator.h
 *
 *  Created on: May 22, 2014
 *      Author: nat543207
 */

#ifndef MAGICSQUAREGENERATOR_H_
#define MAGICSQUAREGENERATOR_H_

class Direction_Controller
{
	private:
		static int Dim_count;
		int** control_matrix;
		int MSD, LSD;
	public:
		~Direction_Controller();
		Direction_Controller(int);
		void Show_Direction_Controller();
		int get_Direction_Element(int, int);
		int* get_Direction_Row(int);
};

class Tuple
{
	private:
		int Tp_Size;
	public:
		int* Tp_data;
		~Tuple();
		Tuple();
		Tuple(int);
		Tuple(int, int*);
		void Show_Tuple();
		void incr_Tuple(Direction_Controller, int, int);
		void decr_Tuple(Direction_Controller, int, int);
		int get_Tuple_component(int);
		void set_Tuple_component(int, int);
		void Equate_Tuple(const Tuple&);
		int Tuple_converter(Tuple);
};

class Magic_Cube
{
	private:
		Direction_Controller* dc;
	public:
	    int Cube_Dimension, Row_Size, Row_Sum, Middle_Digit, Total_Rows, Cube_Offset;
	    Tuple* Start_Tuple, Middle_Tuple, Base_Converter;
	    int** Magic_Data;
	    int* Lookup_Table;
	    int Table_Size;     //formatted output table
	    ~Magic_Cube();
	    Magic_Cube(int, int, bool, int);
	    void calc_Middle_Tuple();
	    void calc_Start_Tuple();
	    void calc_Base_Converter();
	    int Integer_Exponentiation(int, int);
	    void Make_Row(Tuple, int, Tuple*);
	    void Make_Two_Rows(Tuple, int, Tuple*, int*);
	    void Fill_Magic_Data();
	    void Make_Lookup_Table();

};

#endif /* MAGICSQUAREGENERATOR_H_ */
