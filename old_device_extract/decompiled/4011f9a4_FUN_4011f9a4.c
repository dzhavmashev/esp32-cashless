// Function : FUN_4011f9a4
// Address  : 0x4011f9a4
// Size     : 86 bytes


void FUN_4011f9a4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [4];
  char *pcStack_28;
  
  if (*(int *)(param_1 + 4) != 0x12121212) {
    (*(code *)&SUB_4008b530)(param_1,0,0x14);
    *(undefined4 *)(param_1 + 4) = 0x12121212;
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    memw();
    (*(code *)&SUB_4008b530)(auStack_2c,0,0xc);
    pcStack_28 = "p_timer";
    memw();
    uStack_34 = param_2;
    uStack_30 = param_3;
    iVar1 = FUN_4011f868(&uStack_34,param_1 + 0x10);
    if (iVar1 != 0) {
      (*(code *)&SUB_4008effc)(iVar1,"timer)",0x45,"_arm_us","TSTimer");
    }
  }
  return;
}

