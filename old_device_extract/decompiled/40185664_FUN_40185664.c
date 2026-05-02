// Function : FUN_40185664
// Address  : 0x40185664
// Size     : 21 bytes


int FUN_40185664(int param_1,int param_2)

{
  return param_1 / param_2 - ((param_1 % param_2 >> 0x1f) - param_1 % param_2 >> 0x1f);
}

