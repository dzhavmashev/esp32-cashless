// Function : FUN_400dfecc
// Address  : 0x400dfecc
// Size     : 281 bytes


void FUN_400dfecc(int param_1,float param_2,int *param_3)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  int *piVar4;
  undefined8 uVar5;
  undefined2 uStack_26;
  float afStack_24 [9];
  
  pcVar2 = "D: %s)\n";
  if (*(char *)(param_1 + 0x9c) == '\0') {
LAB_400dff11:
    FUN_400f0780(0x3ffc5490,pcVar2);
  }
  else {
    if (0.0 < param_2) {
      if ((*(char *)(param_1 + 0x79) != '\0') && (*(char *)(param_1 + 0x26) == '\0')) {
        pcVar2 = ": %.2f\n";
        goto LAB_400dff11;
      }
      iVar1 = FUN_400dfdec(param_1,param_2);
      if (iVar1 != 0) {
        uVar5 = (*(code *)&SUB_40002c34)(param_2);
        piVar4 = param_3;
        if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
          piVar4 = (int *)*param_3;
        }
        FUN_400f06a4(0x3ffc5490,"2f KGS\n",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20),iVar1,piVar4);
        *(float *)(param_1 + 0x94) = *(float *)(param_1 + 0x94) + param_2;
        if ((*(char *)(param_1 + 0x79) == '\0') || (*(char *)(param_1 + 0x26) == '\0')) {
          FUN_400dfe64(param_1,iVar1,param_3);
        }
        else {
          *(int *)(param_1 + 0x80) = iVar1 + *(int *)(param_1 + 0x80);
          FUN_400f06a4(0x3ffc5490,"D: %s)\n",iVar1);
          iVar1 = FUN_400f1a9c();
          uVar3 = (uint)(iVar1 - *(int *)(param_1 + 0x7c)) / 1000;
          if (uVar3 < *(uint *)(param_1 + 0x80)) {
            func_0x4009246c(*(undefined4 *)(param_1 + 0x98),4,
                            ((*(uint *)(param_1 + 0x80) - uVar3) * 1000000) / 1000,0);
          }
        }
        if (*(int *)(param_1 + 0xc) == 0) {
          return;
        }
        uStack_26 = 0;
        afStack_24[0] = param_2;
        (**(code **)(param_1 + 0x10))(param_1 + 4,param_3,afStack_24,&uStack_26);
        return;
      }
      uVar5 = (*(code *)&SUB_40002c34)();
      pcVar2 = "ialized";
    }
    else {
      uVar5 = (*(code *)&SUB_40002c34)(param_2);
      pcVar2 = "ialized";
    }
    FUN_400f06a4(0x3ffc5490,pcVar2,(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  }
  return;
}

