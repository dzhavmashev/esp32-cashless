// Function : FUN_40115910
// Address  : 0x40115910
// Size     : 36 bytes


void FUN_40115910(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &DAT_3ffc6388;
  iVar1 = 0;
  do {
    if ((puVar2[0x14] != '\0') && (*(int *)(puVar2 + 8) == param_1)) {
      FUN_40115680(iVar1);
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 0x18;
  } while (iVar1 != 10);
  return;
}

