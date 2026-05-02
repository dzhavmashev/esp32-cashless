// Function : FUN_400fd214
// Address  : 0x400fd214
// Size     : 54 bytes


void FUN_400fd214(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 in_PRID;
  
  uVar2 = rsr(in_PRID);
  puVar3 = (undefined4 *)((uVar2 >> 0xd & 1) * 0x20 + 0x3ffc576c);
  iVar5 = 0;
  bVar1 = true;
  do {
    if (((code *)*puVar3 != (code *)0x0) && (iVar4 = (*(code *)*puVar3)(), iVar4 == 0)) {
      bVar1 = false;
    }
    iVar5 = iVar5 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar5 != 8);
  if (bVar1) {
    (*(code *)&LAB_40185673_1)();
  }
  return;
}

