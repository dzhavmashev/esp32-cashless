// Function : FUN_40162394
// Address  : 0x40162394
// Size     : 343 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162394(uint param_1,undefined2 param_2,undefined4 param_3,uint param_4,undefined4 param_5
                 ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_40;
  undefined4 uStack_3c;
  uint uStack_30;
  
  bVar5 = DAT_3ffca1e5;
  uStack_30 = param_1 & 0xff;
  uVar6 = (uint)DAT_3ffca1e5;
  uVar1 = _DAT_3ffca220;
  uVar2 = _DAT_3ffca248;
  uVar3 = _DAT_3ffca250;
  uVar4 = _DAT_3ffca258;
  if (uVar6 == 0) {
    memw();
    FUN_40147fe4(6,0x1000,3,0x3f4358b4,_DAT_3ffca1fc);
    DAT_3ffca1e6 = 1;
    DAT_3ffca1da = (undefined1)uStack_30;
    DAT_3ffca1e7 = bVar5;
    memw();
    memw();
    _DAT_3ffca1f2 = param_2;
    (*(code *)&SUB_4008b3d0)(0x3ffca1db,param_3,6);
    _DAT_3ffca1f8 = FUN_4015167c();
    DAT_3ffca1eb = bVar5;
    DAT_3ffca1ec = bVar5;
    DAT_3ffca1e1 = bVar5;
    DAT_3ffca1e2 = bVar5;
    memw();
    _DAT_3ffca260 = 0;
    _DAT_3ffca264 = 0;
    memw();
    memw();
    _DAT_3ffca214 = uVar6;
    _DAT_3ffca218 = uVar6;
    _DAT_3ffca258 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    memw();
    _DAT_3ffca248 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    memw();
    _DAT_3ffca250 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    memw();
    _DAT_3ffca220 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
    if ((param_4 & 0xffff) == 0) {
      _DAT_3ffca204 = 0x19000;
    }
    else {
      memw();
      _DAT_3ffca204 = (param_4 & 0xffff) << 10;
    }
    memw();
    iVar7 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
    if (iVar7 != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0x1b8))(_DAT_3ffca204 / 100);
    }
    DAT_3ffca1f1 = 0;
    DAT_3ffca2f4 = 0;
    DAT_3ffca1e3 = 1;
    DAT_3ffca1f0 = 1;
    memw();
    memw();
    DAT_3ffca1e4 = (**(code **)(_DAT_3ffc1a34 + 0x194))();
    memw();
    memw();
    FUN_40163d38();
    local_40 = param_7;
    uStack_3c = param_8;
    memw();
    FUN_4018b38c(param_5,&local_40,0);
    FUN_4018a8a8();
    FUN_40162224(4);
    if (DAT_3ffca2f5 != '\0') {
      DAT_3ffca2f5 = '\x01';
    }
    DAT_3ffca1e5 = 1;
    memw();
    memw();
    FUN_401615fc();
    uVar1 = _DAT_3ffca220;
    uVar2 = _DAT_3ffca248;
    uVar3 = _DAT_3ffca250;
    uVar4 = _DAT_3ffca258;
  }
  _DAT_3ffca25c = (undefined4)((ulonglong)uVar4 >> 0x20);
  _DAT_3ffca258 = (undefined4)uVar4;
  _DAT_3ffca254 = (undefined4)((ulonglong)uVar3 >> 0x20);
  _DAT_3ffca250 = (undefined4)uVar3;
  _DAT_3ffca24c = (undefined4)((ulonglong)uVar2 >> 0x20);
  _DAT_3ffca248 = (undefined4)uVar2;
  _DAT_3ffca224 = (undefined4)((ulonglong)uVar1 >> 0x20);
  _DAT_3ffca220 = (undefined4)uVar1;
  return;
}

