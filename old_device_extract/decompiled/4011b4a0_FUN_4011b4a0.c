// Function : FUN_4011b4a0
// Address  : 0x4011b4a0
// Size     : 196 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4011b4a0(undefined2 *param_1)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  
  uVar1 = _DAT_3ffc653c;
  *param_1 = 0x102;
  param_1[1] = 6;
  memw();
  param_1[4] = 0;
  memw();
  memw();
  uVar2 = FUN_40185290(0x8000);
  uStack_28 = (undefined1)uVar1;
  uStack_27 = (undefined1)((uint)uVar1 >> 8);
  *(undefined1 *)(param_1 + 8) = uStack_28;
  *(undefined1 *)((int)param_1 + 0x11) = uStack_27;
  memw();
  uStack_26 = (undefined1)((uint)uVar1 >> 0x10);
  uStack_25 = (undefined1)((uint)uVar1 >> 0x18);
  *(undefined1 *)(param_1 + 9) = uStack_26;
  *(undefined1 *)((int)param_1 + 0x13) = uStack_25;
  param_1[5] = uVar2;
  memw();
  memw();
  (*(code *)&SUB_4008b530)(param_1 + 6,0,4);
  (*(code *)&SUB_4008b530)(param_1 + 10,0,4);
  (*(code *)&SUB_4008b530)(param_1 + 0xc,0,4);
  (*(code *)&SUB_4008b530)(param_1 + 0x16,0,0x40);
  (*(code *)&SUB_4008b530)(param_1 + 0x36,0,0x80);
  (*(code *)&SUB_4008b530)(param_1 + 0x76,0,0x138);
  *(undefined1 *)(param_1 + 0x76) = 99;
  *(undefined1 *)((int)param_1 + 0xed) = 0x82;
  *(undefined1 *)(param_1 + 0x77) = 0x53;
  *(undefined1 *)((int)param_1 + 0xef) = 99;
  memw();
  memw();
  return;
}

