// Function : FUN_400fd764
// Address  : 0x400fd764
// Size     : 58 bytes


void FUN_400fd764(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined1 in_PRID;
  
  for (puVar1 = (undefined4 *)&DAT_3ffbdb60; (undefined4 *)0x3ffbdb5f < puVar1; puVar1 = puVar1 + -2
      ) {
    uVar2 = rsr(in_PRID);
    if ((puVar1[1] & 1 << ((byte)(uVar2 >> 0xd) & 1)) != 0) {
      (*(code *)*puVar1)();
    }
  }
  uVar2 = rsr(in_PRID);
  memw();
  *(undefined1 *)((uVar2 >> 0xd & 1) + 0x3ffc57ed) = 1;
  memw();
  return;
}

