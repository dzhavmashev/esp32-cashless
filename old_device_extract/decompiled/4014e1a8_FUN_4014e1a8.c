// Function : FUN_4014e1a8
// Address  : 0x4014e1a8
// Size     : 98 bytes


int FUN_4014e1a8(undefined1 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_40150e2c();
  *(undefined1 *)(iVar2 + 0x90) = param_1;
  memw();
  bVar1 = *(byte *)(iVar2 + 0x9f);
  memw();
  iVar3 = FUN_40150e8c(5,param_1,DAT_3ffc8a05 == '\0');
  if (iVar3 == 0) {
    *(undefined1 *)((uint)bVar1 * 0x8c + iVar2 + 299) = param_1;
    memw();
    memw();
    iVar3 = FUN_40150e8c(0xd,iVar2 + 0xa0,DAT_3ffc8a05 == '\0');
    if (iVar3 == 0) {
      iVar3 = FUN_40150e38();
    }
  }
  return iVar3;
}

