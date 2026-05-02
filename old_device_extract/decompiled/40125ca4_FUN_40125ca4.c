// Function : FUN_40125ca4
// Address  : 0x40125ca4
// Size     : 78 bytes


undefined1 *
FUN_40125ca4(undefined1 *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  undefined1 *puVar1;
  
  *param_1 = 0xdd;
  param_1[1] = (char)param_6 + '\x04' + (char)param_4;
  param_1[2] = (char)((uint)param_2 >> 0x18);
  param_1[3] = (char)((uint)param_2 >> 0x10);
  param_1[4] = (char)((uint)param_2 >> 8);
  param_1[5] = (char)param_2;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(param_1 + 6,param_3,param_4);
  puVar1 = param_1 + 6 + param_4;
  if (param_5 != 0) {
    (*(code *)&SUB_4008b3d0)(puVar1,param_5,param_6);
    puVar1 = puVar1 + param_6;
  }
  return puVar1;
}

