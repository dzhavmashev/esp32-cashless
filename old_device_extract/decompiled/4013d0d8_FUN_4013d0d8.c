// Function : FUN_4013d0d8
// Address  : 0x4013d0d8
// Size     : 215 bytes


int FUN_4013d0d8(undefined1 *param_1,int param_2,int param_3,uint *param_4,int param_5,byte *param_6
                ,byte *param_7)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  
  uVar5 = *param_4;
  memw();
  iVar3 = FUN_401866a8(param_1);
  iVar6 = -0x20;
  if (iVar3 != 0) {
    func_0x4013cf40();
    memw();
    param_1[1] = 0;
    memw();
    uVar2 = FUN_401687e8(param_1 + 2,*param_1,1);
    pbVar4 = param_7 + param_3;
    memw();
    param_1[1] = uVar2;
    if (param_2 == 0) {
      while (pbVar4 != param_7) {
        if ((uVar5 == 0) && (iVar6 = FUN_4013cee0(param_1,param_5,param_5), iVar6 != 0))
        goto LAB_4013d15c;
        pbVar7 = (byte *)(param_5 + uVar5);
        bVar1 = *param_6;
        uVar5 = uVar5 + 1 & 0xf;
        param_6 = param_6 + 1;
        *param_7 = bVar1 ^ *pbVar7;
        param_7 = param_7 + 1;
        *pbVar7 = bVar1;
        memw();
        memw();
      }
    }
    else {
      while (param_7 != pbVar4) {
        if (uVar5 == 0) {
          memw();
          iVar6 = FUN_4013cee0(param_1,param_5,param_5);
          if (iVar6 != 0) goto LAB_4013d15c;
        }
        pbVar7 = (byte *)(param_5 + uVar5);
        bVar1 = *param_6;
        uVar5 = uVar5 + 1 & 0xf;
        param_6 = param_6 + 1;
        bVar1 = *pbVar7 ^ bVar1;
        *param_7 = bVar1;
        param_7 = param_7 + 1;
        *pbVar7 = bVar1;
        memw();
      }
      memw();
    }
    iVar6 = 0;
    *param_4 = uVar5;
    memw();
LAB_4013d15c:
    memw();
    FUN_4013cf58();
  }
  return iVar6;
}

