// Function : FUN_40113f2c
// Address  : 0x40113f2c
// Size     : 38 bytes


void FUN_40113f2c(void)

{
  int iVar1;
  
  iVar1 = FUN_4010b058(1);
  if (iVar1 != 0) {
    (*(code *)&SUB_4008b530)(iVar1,0,0x50);
    *(undefined1 *)(iVar1 + 0x33) = 0x40;
    *(undefined1 *)(iVar1 + 0x45) = 0x40;
    memw();
  }
  memw();
  return;
}

