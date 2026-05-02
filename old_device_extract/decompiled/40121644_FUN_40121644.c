// Function : FUN_40121644
// Address  : 0x40121644
// Size     : 168 bytes


undefined4 FUN_40121644(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  (*(code *)&SUB_40091388)();
  uVar1 = (*(code *)&SUB_400913ac)();
  param_1 = param_1 * 4;
  uVar2 = (*(code *)&SUB_400913ac)(*(undefined4 *)(param_1 + 0x3ffc6d6c));
  if (uVar2 < uVar1) {
    (*(code *)&SUB_400913d0)(*(undefined4 *)(param_1 + 0x3ffc6d6c),uVar1);
  }
  memw();
  (*(code *)&SUB_40090010)(*(undefined4 *)(param_1 + 0x3ffc6d64),0xffffffff);
  (*(code *)&SUB_400913d0)(*(undefined4 *)(param_1 + 0x3ffc6d6c),uVar1);
  memw();
  *(undefined4 *)(param_1 + 0x3ffc6d4c) = param_2;
  memw();
  *(undefined4 *)(param_1 + 0x3ffc6d44) = param_3;
  memw();
  *(undefined4 *)(param_1 + 0x3ffc6d3c) = param_4;
  memw();
  (*(code *)&SUB_4008fab8)(*(undefined4 *)(param_1 + 0x3ffc6d5c),0,0);
  (*(code *)&SUB_40090010)(*(undefined4 *)(param_1 + 0x3ffc6d54),0xffffffff);
  (*(code *)&SUB_4008fab8)(*(undefined4 *)(param_1 + 0x3ffc6d64),0,0);
  return 0;
}

