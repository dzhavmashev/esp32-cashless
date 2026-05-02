// Function : FUN_40146aac
// Address  : 0x40146aac
// Size     : 88 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40146aac(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  iVar1 = FUN_401460c8();
  uVar2 = 0x3001;
  if ((iVar1 != 0) && (uVar2 = 0x3002, 1 < DAT_3ffc89d9)) {
    puVar3 = (undefined1 *)(**(code **)(_DAT_3ffc1a34 + 0x178))(0x18);
    uVar2 = 0x101;
    if (puVar3 != (undefined1 *)0x0) {
      *puVar3 = 0x25;
      memw();
      puVar3[8] = 0;
      *(undefined4 *)(puVar3 + 4) = 0x40150068;
      puVar3[9] = 0;
      puVar3[10] = 0;
      memw();
      *(uint *)(puVar3 + 0xc) = param_1 & 0xffff;
      memw();
      uVar2 = FUN_40150444();
    }
  }
  return uVar2;
}

