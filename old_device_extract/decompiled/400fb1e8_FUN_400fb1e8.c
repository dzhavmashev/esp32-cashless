// Function : FUN_400fb1e8
// Address  : 0x400fb1e8
// Size     : 177 bytes


uint FUN_400fb1e8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0xffffffff;
  if ((((param_3 & 0x1f) != 0) ||
      (uVar3 = *(uint *)(param_1 + 0x38), uVar2 = uVar3, uVar3 == 0xffffffff)) ||
     (uVar2 = *(uint *)(param_1 + 0x3c), uVar2 == 0xffffffff)) goto LAB_400fb232;
  if (param_2 < 0x3ff00000) {
    uVar1 = (*(code *)&SUB_40094d60)(param_3);
    uVar2 = 0x101;
    if (uVar1 == 0) goto LAB_400fb232;
    (*(code *)&SUB_4008b3d0)(uVar1,param_2,param_3);
    if (uVar3 < 0x7e) goto LAB_400fb241;
    uVar2 = 0xffffffff;
    if (param_2 == uVar1) goto LAB_400fb22c;
LAB_400fb25e:
    (*(code *)&SUB_40094d80)(uVar1);
LAB_400fb266:
    if (uVar2 == 0) {
      uVar3 = param_3 >> 5 & 0xffff;
      uVar2 = FUN_40184aa4(param_1,*(int *)(param_1 + 0x38),*(int *)(param_1 + 0x38) + uVar3,2);
      if (uVar2 == 0) {
        *(short *)(param_1 + 0x40) = (short)(param_3 >> 5) + *(short *)(param_1 + 0x40);
        memw();
        *(uint *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + uVar3;
        memw();
      }
      goto LAB_400fb232;
    }
  }
  else {
    uVar1 = param_2;
    if (uVar3 < 0x7e) {
LAB_400fb241:
      uVar2 = (**(code **)(**(int **)(param_1 + 0x50) + 0x18))
                        (*(int **)(param_1 + 0x50),*(int *)(param_1 + 8) + 0x40 + uVar3 * 0x20,uVar1
                         ,param_3);
      if (param_2 != uVar1) goto LAB_400fb25e;
      goto LAB_400fb266;
    }
LAB_400fb22c:
    uVar2 = 0xffffffff;
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
LAB_400fb232:
  memw();
  return uVar2;
}

