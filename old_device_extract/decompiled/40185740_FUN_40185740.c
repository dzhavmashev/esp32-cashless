// Function : FUN_40185740
// Address  : 0x40185740
// Size     : 45 bytes


void FUN_40185740(byte param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  iVar1 = 0;
  while (iVar1 != param_4) {
    pbVar2 = (byte *)(param_3 + iVar1);
    pbVar3 = (byte *)(param_2 + iVar1);
    pbVar4 = (byte *)(param_5 + iVar1);
    iVar1 = iVar1 + 1;
    *pbVar4 = *pbVar2 ^ param_1 & (*pbVar2 ^ *pbVar3);
    memw();
    memw();
  }
  return;
}

