// Function : FUN_4017c3b0
// Address  : 0x4017c3b0
// Size     : 39 bytes


int FUN_4017c3b0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_4017c100(param_1,1);
  if (iVar1 == 0) {
    iVar1 = (*(code *)&SUB_40094c54)(&DAT_3f4260d0,0x140,0,"/dtoa.c");
  }
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  return iVar1;
}

