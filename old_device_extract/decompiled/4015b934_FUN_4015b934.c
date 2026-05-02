// Function : FUN_4015b934
// Address  : 0x4015b934
// Size     : 85 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b934(int param_1)

{
  int iVar1;
  char *pcVar2;
  undefined1 auStack_30 [48];
  
  iVar1 = _DAT_3ffbfc54;
  pcVar2 = (char *)FUN_4015b1c4();
  FUN_4014eb04(0,auStack_30);
  if (*(char *)(param_1 + 0xab) != *pcVar2) {
    FUN_4015b52c(param_1 + 0xab,0,0,0x4015b92c,0,param_1);
    return;
  }
  memw();
  FUN_40153c94(param_1,auStack_30,param_1 + 4,param_1 + 4,iVar1 + 8,*(undefined1 *)(iVar1 + 4),0,0);
  return;
}

