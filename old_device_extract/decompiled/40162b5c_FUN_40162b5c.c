// Function : FUN_40162b5c
// Address  : 0x40162b5c
// Size     : 89 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162b5c(int param_1)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  bVar1 = **(byte **)(*(int *)(param_1 + 4) + 4);
  if (((bVar1 & 0xc) == 0) && ((bVar1 & 0xf0) == 0x80)) {
    uVar3 = 4;
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x1a0);
  }
  else if ((bVar1 & 0xc) == 0) {
    if (((bVar1 & 0xf0) + 0x60 & 0xd0) != 0) {
      return;
    }
    uVar3 = 7;
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x1a0);
  }
  else {
    if ((bVar1 & 0xc) != 8) {
      return;
    }
    if ((bVar1 & 0x70) != 0x40) {
      return;
    }
    uVar3 = 9;
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x1a0);
  }
  (*pcVar2)(uVar3);
  return;
}

