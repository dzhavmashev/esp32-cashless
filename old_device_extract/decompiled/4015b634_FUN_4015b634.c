// Function : FUN_4015b634
// Address  : 0x4015b634
// Size     : 58 bytes


int FUN_4015b634(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  do {
    uVar3 = (uint)DAT_3ffca0b7;
    if (DAT_3ffca0b6 <= uVar3) {
      return 0;
    }
    DAT_3ffca0b7 = DAT_3ffca0b7 + 1;
    iVar1 = *(int *)((uVar3 + 0x3a8) * 4 + 0x3ffc9200);
    memw();
    memw();
    iVar2 = FUN_4015b24c(*(undefined1 *)(iVar1 + 0xab));
  } while ((*(uint *)(iVar2 + 8) & 0x200) != 0);
  return iVar1;
}

