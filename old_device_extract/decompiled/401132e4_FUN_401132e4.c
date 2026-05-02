// Function : FUN_401132e4
// Address  : 0x401132e4
// Size     : 30 bytes


void FUN_401132e4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 1;
  puVar1 = &DAT_3f4115f0;
  do {
    iVar2 = iVar2 + 1;
    FUN_40113258(*puVar1,0x40113220,puVar1);
    puVar1 = puVar1 + 2;
  } while (iVar2 != 6);
  return;
}

