// Function : FUN_401569d8
// Address  : 0x401569d8
// Size     : 39 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401569d8(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = _DAT_3ffc8920;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)&SUB_4008b33c)(puVar2 + 1,param_1,6);
    if (iVar1 == 0) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return 1;
}

