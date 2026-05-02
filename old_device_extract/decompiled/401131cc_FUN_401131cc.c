// Function : FUN_401131cc
// Address  : 0x401131cc
// Size     : 92 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401131cc(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_4010b058(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)(*(code *)&SUB_40094c54)("s empty",0xca,"timeout","p_write");
  }
  *puVar1 = 0;
  puVar3 = _DAT_3ffc6374;
  puVar1[2] = param_2;
  puVar1[3] = param_3;
  puVar1[1] = param_1;
  if (puVar3 != (undefined4 *)0x0) {
    if (param_1 - puVar3[1] < 0) {
      *puVar1 = puVar3;
      memw();
    }
    else {
      do {
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar2;
        if (puVar3 == (undefined4 *)0x0) break;
      } while (-1 < param_1 - puVar3[1]);
      *puVar1 = puVar3;
      *puVar2 = puVar1;
      memw();
      puVar1 = _DAT_3ffc6374;
    }
  }
  _DAT_3ffc6374 = puVar1;
  memw();
  return;
}

