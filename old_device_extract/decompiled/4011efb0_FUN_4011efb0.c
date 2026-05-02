// Function : FUN_4011efb0
// Address  : 0x4011efb0
// Size     : 66 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4011efb0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_3ffc66f0 == '\0') {
    if (_DAT_3ffbe0e8 != 0) {
      uVar1 = (*(code *)&SUB_40094b80)();
      (*(code *)&SUB_40007d54)("",uVar1,"nternal");
    }
    (*(code *)&SUB_40094bc8)();
  }
  iVar2 = FUN_4011f574();
  if (((iVar2 != 1) && (iVar2 != 0)) && (iVar2 != 2)) {
    iVar2 = 3;
  }
  return iVar2;
}

