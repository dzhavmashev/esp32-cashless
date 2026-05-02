// Function : FUN_400e66d0
// Address  : 0x400e66d0
// Size     : 147 bytes


void FUN_400e66d0(uint *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if ((int)*param_1 < 0) {
    FUN_400f0780(0x3ffc5490,"UT mode");
  }
  else {
    FUN_400f06a4(0x3ffc5490,"ialized",param_2);
    FUN_400f1a40(*param_1 & 0xff,(char)param_1[3] == '\0');
    FUN_400f1960((char)*param_1,3);
    for (iVar1 = 0; iVar1 != param_2; iVar1 = iVar1 + 1) {
      if ((char)param_1[3] == '\0') {
        FUN_400f1a40();
        FUN_400f1ab4(param_1[2]);
        FUN_400f1a40((char)*param_1,1);
        uVar2 = param_1[1];
      }
      else {
        FUN_400f1a40((char)*param_1,1);
        FUN_400f1ab4(param_1[1]);
        FUN_400f1a40((char)*param_1,0);
        uVar2 = param_1[2];
      }
      FUN_400f1ab4(uVar2);
    }
    FUN_400f1960((char)*param_1,1);
    FUN_400f06a4(0x3ffc5490,"pin %d\n",iVar1);
  }
  return;
}

