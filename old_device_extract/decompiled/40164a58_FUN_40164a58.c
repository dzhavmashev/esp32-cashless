// Function : FUN_40164a58
// Address  : 0x40164a58
// Size     : 216 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40164a58(int param_1,char param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  cVar1 = DAT_3ffc06f4;
  if (DAT_3ffc06f4 == param_2) {
    uVar2 = FUN_401649e8(param_1);
    if (*(byte *)(param_1 + 0x1e) + 0x14 < uVar2) {
      FUN_40186c44(param_1,3);
      *(undefined1 *)(param_1 + 0xe) = 3;
      memw();
      *(uint *)(param_1 + 0x60) = (uint)(byte)(cVar1 - 1) * 0xc + *(int *)(param_1 + 0x70);
      memw();
      FUN_401641bc(param_1);
      iVar4 = 0;
      do {
        if (((uint)*(byte *)(param_1 + 0x10) & 1 << ((byte)iVar4 & 0x1f)) != 0) {
          FUN_40164658(param_1,3,iVar4);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 8);
      return;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xc) = 0;
    memw();
    if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
      memw();
      iVar4 = _DAT_3ff73c00 + _DAT_3ffc1a30;
    }
    else {
      memw();
      iVar4 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    }
    *(int *)(param_1 + 0x50) = iVar4;
    *(undefined1 *)(param_1 + 0xd) =
         *(undefined1 *)((uint)(byte)(param_2 + 1) * 0xc + *(int *)(param_1 + 0x70));
    memw();
    memw();
    uVar3 = FUN_40163f8c();
    FUN_40186c6c(param_1,uVar3);
  }
  FUN_401641ec(param_1);
  return;
}

