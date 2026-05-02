// Function : FUN_4015f6d8
// Address  : 0x4015f6d8
// Size     : 67 bytes


undefined4 FUN_4015f6d8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  *(short *)(param_1 * 0x14 + 0x3ffbff22) = (short)param_2;
  memw();
  memw();
  while( true ) {
    if (param_2 == 0) {
      return 0;
    }
    param_2 = param_2 + -1;
    iVar1 = FUN_4018b19c(param_1 * 0x14 + 0x3ffbff18,param_3,0);
    if (iVar1 == 0) break;
    FUN_4018a7b8();
  }
  FUN_40147fe4(1,0x400,2,0x3f436e8e,param_1);
  return 0x101;
}

