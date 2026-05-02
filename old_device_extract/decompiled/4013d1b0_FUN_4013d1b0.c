// Function : FUN_4013d1b0
// Address  : 0x4013d1b0
// Size     : 173 bytes


int FUN_4013d1b0(undefined1 *param_1,int param_2,uint *param_3,char *param_4,int param_5,
                byte *param_6,byte *param_7)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  undefined1 uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  
  uVar7 = *param_3;
  memw();
  iVar5 = FUN_401866a8(param_1);
  iVar8 = -0x20;
  if (iVar5 != 0) {
    func_0x4013cf40();
    memw();
    param_1[1] = 0;
    memw();
    uVar4 = FUN_401687e8(param_1 + 2,*param_1,1);
    pbVar6 = param_7 + param_2;
    memw();
    param_1[1] = uVar4;
    while (param_7 != pbVar6) {
      if (uVar7 == 0) {
        memw();
        iVar8 = FUN_4013cee0(param_1,param_4,param_5);
        pcVar10 = param_4 + 0xf;
        if (iVar8 != 0) goto LAB_4013d1f5;
        do {
          cVar2 = *pcVar10;
          *pcVar10 = cVar2 + '\x01';
          memw();
          if ((char)(cVar2 + '\x01') != '\0') break;
          bVar1 = param_4 != pcVar10;
          pcVar10 = pcVar10 + -1;
        } while (bVar1);
      }
      pbVar9 = (byte *)(param_5 + uVar7);
      bVar3 = *param_6;
      uVar7 = uVar7 + 1 & 0xf;
      param_6 = param_6 + 1;
      *param_7 = *pbVar9 ^ bVar3;
      memw();
      param_7 = param_7 + 1;
      memw();
    }
    iVar8 = 0;
    *param_3 = uVar7;
LAB_4013d1f5:
    memw();
    FUN_4013cf58();
  }
  return iVar8;
}

