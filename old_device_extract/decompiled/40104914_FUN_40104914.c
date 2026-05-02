// Function : FUN_40104914
// Address  : 0x40104914
// Size     : 82 bytes


void FUN_40104914(int param_1)

{
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  memw();
  (*(code *)&SUB_4008b530)(param_1 + 0x44,0,0x68);
  (*(code *)&SUB_4008b530)(param_1 + 0xac,0,0x68);
  (*(code *)&SUB_4008b530)(param_1 + 0x174,0,0x24);
  (*(code *)&SUB_4008b530)(param_1 + 0x198,0,0x24);
  return;
}

