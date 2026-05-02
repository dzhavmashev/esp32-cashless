// Function : FUN_401862dc
// Address  : 0x401862dc
// Size     : 75 bytes


byte FUN_401862dc(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  undefined1 uStack_21;
  
  memw();
  uStack_21 = 0;
  iVar3 = 0;
  while (iVar3 != param_3) {
    pbVar1 = (byte *)(param_1 + iVar3);
    memw();
    pbVar2 = (byte *)(param_2 + iVar3);
    iVar3 = iVar3 + 1;
    memw();
    memw();
    uStack_21 = *pbVar2 ^ *pbVar1 | uStack_21;
    memw();
    memw();
  }
  memw();
  memw();
  return uStack_21;
}

