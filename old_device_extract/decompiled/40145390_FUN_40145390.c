// Function : FUN_40145390
// Address  : 0x40145390
// Size     : 39 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_40145390(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = DAT_3ffc18f8 == '\0';
  if (!bVar1) {
    uVar2 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
    FUN_40168698(0x3ffc186b,uVar2);
  }
  return bVar1;
}

