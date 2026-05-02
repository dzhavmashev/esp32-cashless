// Function : FUN_4013d260
// Address  : 0x4013d260
// Size     : 201 bytes


int FUN_4013d260(undefined1 *param_1,int param_2,uint *param_3,int param_4,byte *param_5,
                byte *param_6)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  if ((param_1 != (undefined1 *)0x0) && (param_3 != (uint *)0x0)) {
    bVar2 = param_4 == 0;
    bVar3 = param_5 == (byte *)0x0;
    if ((!bVar2 && !bVar3) && (param_6 != (byte *)0x0 && (!bVar2 && !bVar3))) {
      uVar6 = *param_3;
      if (0xf < uVar6) {
        return -0x21;
      }
      memw();
      iVar5 = FUN_401866a8(param_1);
      if (iVar5 == 0) {
        return -0x20;
      }
      func_0x4013cf40();
      memw();
      param_1[1] = param_6 == (byte *)0x0 || (bVar2 || bVar3);
      memw();
      uVar4 = FUN_401687e8(param_1 + 2,*param_1,1);
      pbVar8 = param_6 + param_2;
      memw();
      param_1[1] = uVar4;
      while (param_6 != pbVar8) {
        if (uVar6 == 0) {
          memw();
          iVar5 = FUN_4013cee0(param_1,param_4,param_4);
          if (iVar5 != 0) goto LAB_4013d316;
        }
        pbVar7 = (byte *)(param_4 + uVar6);
        bVar1 = *param_5;
        uVar6 = uVar6 + 1 & 0xf;
        param_5 = param_5 + 1;
        *param_6 = *pbVar7 ^ bVar1;
        memw();
        param_6 = param_6 + 1;
        memw();
      }
      *param_3 = uVar6;
      iVar5 = 0;
      memw();
LAB_4013d316:
      memw();
      FUN_4013cf58();
      return iVar5;
    }
  }
  return -0x21;
}

