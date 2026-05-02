// Function : FUN_4012d570
// Address  : 0x4012d570
// Size     : 55 bytes


undefined4 FUN_4012d570(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffff9a00;
  if (*(int *)(param_1 + 0x14) == 3) {
    if (param_2 == 4) {
      iVar1 = *(int *)(param_1 + 0x44);
      pcVar2 = (code *)&DAT_4012ba7c;
    }
    else if (param_2 == 5) {
      iVar1 = *(int *)(param_1 + 0x44);
      pcVar2 = FUN_4012bb50;
    }
    else {
      if (param_2 != 2) goto LAB_4012d58e;
      iVar1 = *(int *)(param_1 + 0x44);
      pcVar2 = (code *)&DAT_4012bc58;
    }
    uVar3 = 0;
    *(code **)(iVar1 + 0x1c) = pcVar2;
  }
LAB_4012d58e:
  memw();
  return uVar3;
}

