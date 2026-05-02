// Function : FUN_400ecfc4
// Address  : 0x400ecfc4
// Size     : 48 bytes


undefined1 FUN_400ecfc4(undefined4 *param_1,int param_2,undefined1 param_3)

{
  undefined1 auStack_21 [33];
  
  if ((*(char *)(param_1 + 1) == '\x01') && (param_2 != 0)) {
    auStack_21[0] = param_3;
    FUN_400f983c(*param_1,param_2,auStack_21);
    param_3 = auStack_21[0];
  }
  return param_3;
}

