// Function : FUN_4015a720
// Address  : 0x4015a720
// Size     : 293 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_4015a720(uint param_1,undefined4 param_2,undefined1 param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,uint param_8,uint param_9)

{
  bool bVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  
  if ((int)param_9 < 2) {
    FUN_4015a1cc(param_3,param_9 & 0xff);
  }
  if (param_4 != 2) {
    FUN_4015fdf8(param_9);
    bVar1 = _DAT_3ffc89f4 == 0;
    memw();
    iVar3 = FUN_4015a254(0,param_2);
    memw();
    FUN_4015fa0c(0,param_1 & 0xff,param_3,param_2,param_9 & 0xff,param_7,param_8 & 0xff,bVar1,
                 iVar3 != 0);
    if (param_4 == 0) {
      return 0;
    }
  }
  FUN_40162d48();
  puVar2 = (undefined2 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(param_8 + 0xa8);
  if (puVar2 == (undefined2 *)0x0) {
    return 0x101;
  }
  FUN_4015a5d4();
  FUN_4015a190(param_9 & 0xff,puVar2);
  *(uint *)(puVar2 + 0x52) = param_8;
  memw();
  (*(code *)&SUB_4008b3d0)(puVar2 + 0x54,param_7,param_8);
  if (param_1 == 2) {
    uVar4 = 0x3ffbfee8;
  }
  else if (param_1 == 3) {
    uVar4 = 0x3ffbfeb8;
  }
  else {
    if ((param_1 & 0xfffffffb) != 1) {
      if (param_1 == 4) {
        *(undefined4 *)(puVar2 + 0x50) = 0x3ffbfed0;
        puVar5 = puVar2 + 4;
        do {
          puVar6 = puVar5 + 4;
          memw();
          (*(code *)&SUB_4008b3d0)(puVar5,param_5,8);
          puVar5 = puVar6;
        } while (puVar6 != puVar2 + 0x4c);
      }
      goto LAB_4015a82c;
    }
    uVar4 = 0x3ffbff00;
  }
  *(undefined4 *)(puVar2 + 0x50) = uVar4;
  memw();
LAB_4015a82c:
  *puVar2 = (short)param_9;
  memw();
  memw();
  (*(code *)&SUB_4008b3d0)(puVar2 + 0x4c,param_5,8);
  return 0;
}

