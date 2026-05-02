// Function : FUN_4018baa4
// Address  : 0x4018baa4
// Size     : 84 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_4018baa4(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  
  if (((DAT_3ffc1a44 != '\0') && (memw(), DAT_3ffc1a3c == '\0')) && (_DAT_3ffc1a40 != 0)) {
    iVar1 = (*(code *)&SUB_4008b33c)(param_1,0x3ffca1db,6);
    return iVar1 == 0;
  }
  bVar2 = false;
  if (DAT_3ffca1e5 != '\0') {
    iVar1 = (*(code *)&SUB_4008b33c)(param_1,0x3ffca1db,6);
    bVar2 = false;
    if (iVar1 == 0) {
      bVar2 = true;
    }
  }
  return bVar2;
}

