// Function : FUN_40161bc4
// Address  : 0x40161bc4
// Size     : 50 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40161bc4(void)

{
  code *pcVar1;
  int iVar2;
  
  (*(code *)&SUB_40087d08)(1);
  pcVar1 = *(code **)(_DAT_3ffc1a34 + 0x1c8);
  iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x1cc))();
  iVar2 = (*pcVar1)(iVar2 + 1);
  if (iVar2 == 0) {
    FUN_40161a8c();
  }
  (*(code *)&SUB_40087d08)(1,0);
  return;
}

