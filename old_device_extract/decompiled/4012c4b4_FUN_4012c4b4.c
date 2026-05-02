// Function : FUN_4012c4b4
// Address  : 0x4012c4b4
// Size     : 38 bytes


void FUN_4012c4b4(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (*(int *)(param_1 + 0x14) < 3) {
    puVar1 = (undefined *)0x4012bcfc;
  }
  else if (*(int *)(param_2 + 0xc) == 7) {
    puVar1 = (undefined *)0x4012bce4;
  }
  else {
    puVar1 = &DAT_4012bccc;
  }
  *(undefined **)(*(int *)(param_1 + 0x44) + 0x18) = puVar1;
  memw();
  return;
}

