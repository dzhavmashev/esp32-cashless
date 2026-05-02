// Function : FUN_4010beb4
// Address  : 0x4010beb4
// Size     : 224 bytes


undefined4 FUN_4010beb4(int *param_1,int *param_2,uint param_3,uint param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  
  param_3 = param_3 & 0xffff;
  param_4 = param_4 & 0xffff;
  if ((((param_2 == (int *)0x0) || (*(ushort *)(param_2 + 2) < param_3)) || (param_1 == (int *)0x0))
     || (uVar3 = 0, (uint)*(ushort *)(param_1 + 2) < param_4 + param_3)) {
LAB_4010bf8c:
    uVar2 = 0xf0;
  }
  else {
    do {
      uVar5 = *(ushort *)((int)param_1 + 10) - param_4;
      uVar4 = *(ushort *)((int)param_2 + 10) - uVar3;
      uVar5 = (uVar5 < uVar4) * uVar5 + (uVar5 >= uVar4) * uVar4;
      uVar4 = param_3;
      if (uVar5 <= param_3) {
        uVar4 = uVar5 & 0xffff;
      }
      iVar6 = param_1[1] + param_4;
      param_4 = param_4 + uVar4;
      param_3 = param_3 - uVar4 & 0xffff;
      (*(code *)&SUB_4008b3d0)(iVar6,param_2[1] + uVar3,uVar4);
      uVar3 = uVar3 + uVar4;
      uVar1 = *(ushort *)((int)param_1 + 10);
      if (param_4 <= uVar1) goto LAB_4010bf30;
      pcVar7 = " chain)";
      uVar2 = 0x403;
      while( true ) {
        (*(code *)&SUB_40094c54)("if_init",uVar2,"uf_take",pcVar7);
LAB_4010bf30:
        if (uVar3 <= *(ushort *)((int)param_2 + 10)) break;
        pcVar7 = "to->len";
        uVar2 = 0x404;
      }
      if (*(ushort *)((int)param_2 + 10) == uVar3) {
        param_2 = (int *)*param_2;
        if ((param_2 == (int *)0x0) && (param_3 != 0)) goto LAB_4010bf8c;
        uVar3 = 0;
      }
      if (uVar1 == param_4) {
        param_1 = (int *)*param_1;
        if ((param_1 == (int *)0x0) && (param_3 != 0)) goto LAB_4010bf8c;
        if (param_2 == (int *)0x0) {
          param_4 = 0;
        }
        else {
          param_4 = 0;
LAB_4010bf5c:
          if ((*(short *)((int)param_2 + 10) == (short)param_2[2]) && (*param_2 != 0)) {
            return 0xfa;
          }
        }
        if (param_1 != (int *)0x0) goto LAB_4010bf76;
      }
      else {
        if (param_2 != (int *)0x0) goto LAB_4010bf5c;
LAB_4010bf76:
        if ((*(short *)((int)param_1 + 10) == (short)param_1[2]) && (*param_1 != 0)) {
          return 0xfa;
        }
      }
    } while (param_3 != 0);
    uVar2 = 0;
  }
  return uVar2;
}

