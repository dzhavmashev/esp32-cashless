// Function : FUN_40186c30
// Address  : 0x40186c30
// Size     : 17 bytes


int FUN_40186c30(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (param_1 - param_2) + -1;
  if (param_2 <= param_1) {
    iVar1 = param_1 - param_2;
  }
  return iVar1;
}

