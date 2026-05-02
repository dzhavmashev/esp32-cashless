// Function : FUN_400f9220
// Address  : 0x400f9220
// Size     : 30 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f9220(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 == '\0') {
    uVar1 = FUN_400f92d8(_DAT_3ffc56b8);
  }
  else {
    uVar1 = (*(code *)&SUB_40082a94)();
  }
  return uVar1;
}

