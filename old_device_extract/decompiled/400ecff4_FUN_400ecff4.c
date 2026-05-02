// Function : FUN_400ecff4
// Address  : 0x400ecff4
// Size     : 48 bytes


undefined2 FUN_400ecff4(undefined4 *param_1,int param_2,undefined2 param_3)

{
  undefined2 auStack_22 [17];
  
  if ((*(char *)(param_1 + 1) == '\x01') && (param_2 != 0)) {
    auStack_22[0] = param_3;
    FUN_400f98c4(*param_1,param_2,auStack_22);
    param_3 = auStack_22[0];
  }
  return param_3;
}

