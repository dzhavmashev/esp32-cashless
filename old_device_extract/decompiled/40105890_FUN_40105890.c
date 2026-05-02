// Function : FUN_40105890
// Address  : 0x40105890
// Size     : 145 bytes


int FUN_40105890(undefined4 param_1,int param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  uVar2 = param_3 >> 4;
  while( true ) {
    iVar4 = uVar1 * 0x10;
    uVar1 = uVar1 + 1;
    iVar5 = param_4 + iVar4;
    if (uVar2 < uVar1) break;
    *(char *)(param_5 + 0xe) = (char)(uVar1 >> 8);
    *(char *)(param_5 + 0xf) = (char)uVar1;
    memw();
    memw();
    FUN_401021b8(param_1,param_5,iVar5);
    FUN_401850c4(iVar5,param_2 + iVar4);
  }
  iVar4 = uVar2 + 1;
  pbVar3 = (byte *)(param_4 + uVar2 * 0x10);
  if ((param_3 & 0xf) != 0) {
    *(char *)(param_5 + 0xf) = (char)iVar4;
    *(char *)(param_5 + 0xe) = (char)((uint)iVar4 >> 8);
    memw();
    memw();
    FUN_401021b8(param_1,param_5,pbVar3);
    iVar4 = 1;
    *pbVar3 = *(byte *)(param_2 + uVar2 * 0x10) ^ *pbVar3;
    memw();
  }
  memw();
  return iVar4;
}

