// Function : FUN_40145d48
// Address  : 0x40145d48
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40145d48(undefined1 param_1,undefined1 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_40189d50();
  pcVar1 = _DAT_3ffc7900;
  if (iVar2 == 0) {
    memw();
    memw();
    DAT_3ffc78fc = param_1;
    DAT_3ffc78fd = param_2;
    FUN_40189d78();
    uVar3 = 0;
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(param_1,param_2);
      return 0;
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

