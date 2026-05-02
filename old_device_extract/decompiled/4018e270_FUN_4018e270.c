// Function : FUN_4018e270
// Address  : 0x4018e270
// Size     : 35 bytes


int FUN_4018e270(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    param_3 = param_2;
  }
  iVar1 = FUN_4018e114(param_1,param_3);
  if (iVar1 != 0) {
    FUN_4018dfe4(iVar1,param_1 + *(int *)(iVar1 + 0x14),param_2 - *(int *)(iVar1 + 0x14));
  }
  return iVar1;
}

