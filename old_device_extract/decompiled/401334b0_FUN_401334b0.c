// Function : FUN_401334b0
// Address  : 0x401334b0
// Size     : 70 bytes


void FUN_401334b0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  iVar2 = FUN_40186358(param_4,param_5);
  bVar1 = (char)((byte)((uint)-iVar2 >> 0x18) | (byte)((uint)iVar2 >> 0x18)) >> 7;
  iVar2 = 0;
  while (iVar2 != param_3) {
    pbVar4 = (byte *)(param_1 + iVar2);
    pbVar3 = (byte *)(param_2 + iVar2);
    iVar2 = iVar2 + 1;
    *pbVar4 = bVar1 & *pbVar3 | (bVar1 ^ 0xff) & *pbVar4;
    memw();
    memw();
  }
  return;
}

