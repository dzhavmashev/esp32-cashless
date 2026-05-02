// Function : FUN_401521c0
// Address  : 0x401521c0
// Size     : 49 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401521c0(int param_1,uint param_2)

{
  if (((_DAT_3ffc8874 != (ushort *)0x0) && (param_1 != 0)) && (param_2 < 5)) {
    (*(code *)&SUB_4008b3d0)(param_1,_DAT_3ffc8874 + 1,*_DAT_3ffc8874);
    param_1 = param_1 + (uint)*_DAT_3ffc8874;
  }
  return param_1;
}

