// Function : FUN_40172568
// Address  : 0x40172568
// Size     : 61 bytes


void FUN_40172568(int param_1)

{
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [9];
  
  uStack_28 = *(undefined4 *)(param_1 + 0x10);
  auStack_24[0] = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  uStack_2c = 0;
  FUN_40172558(auStack_24);
  FUN_40172558(&uStack_2c);
  uStack_28 = *(undefined4 *)(param_1 + 0x18);
  auStack_24[0] = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  uStack_2c = 0;
  FUN_40172558(auStack_24);
  FUN_40172558(&uStack_2c);
  *(undefined1 *)(param_1 + 0x20) = 0;
  return;
}

