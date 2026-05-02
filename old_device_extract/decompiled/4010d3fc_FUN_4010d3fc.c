// Function : FUN_4010d3fc
// Address  : 0x4010d3fc
// Size     : 216 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4010d3fc(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int in_t0;
  
  if (param_1 != 0) {
    iVar7 = *(int *)(param_1 + 0x3c);
    if (iVar7 == 1) {
      iVar7 = in_t0;
      (*(code *)&SUB_40094c54)(" LISTEN",0x241,"ann_wnd","leaking");
    }
    if (iVar7 == 10) {
      FUN_4010d33c(&DAT_3ffc8418,param_1);
      FUN_4010ca80(param_1);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x50);
      uVar6 = *(undefined4 *)(param_1 + 0x7c);
      pcVar4 = *(code **)(param_1 + 0xbc);
      uVar5 = *(undefined4 *)(param_1 + 0x38);
      sVar2 = *(short *)(param_1 + 0x42);
      if (iVar7 == 0) {
        param_2 = 0;
        if (sVar2 != 0) {
          iVar7 = _DAT_3ffc8410;
          if (_DAT_3ffc8410 == param_1) {
            _DAT_3ffc8410 = *(int *)(param_1 + 0x34);
          }
          else {
            do {
              iVar1 = iVar7;
              if (iVar1 == 0) goto LAB_4010d452;
              iVar7 = *(int *)(iVar1 + 0x34);
            } while (*(int *)(iVar1 + 0x34) != param_1);
            *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_1 + 0x34);
            memw();
          }
LAB_4010d452:
          sVar2 = 0;
          param_2 = 0;
          *(undefined4 *)(param_1 + 0x34) = 0;
        }
      }
      else {
        FUN_4010d33c(&DAT_3ffc840c,param_1);
        DAT_3ffc8408 = 1;
        memw();
        memw();
      }
      if (*(int *)(param_1 + 0x9c) != 0) {
        memw();
        FUN_4010ce5c();
      }
      if (*(int *)(param_1 + 0x98) != 0) {
        FUN_4010ce5c();
      }
      if (*(int *)(param_1 + 0xa0) != 0) {
        FUN_4010ce5c();
      }
      FUN_4010caa8(param_1);
      if (param_2 != 0) {
        memw();
        FUN_40110c08(param_1,uVar6,uVar3,param_1,param_1 + 0x18,sVar2,
                     *(undefined2 *)(param_1 + 0x44));
      }
      FUN_4010ca80(param_1);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(uVar5,0xfffffff3);
      }
    }
  }
  return;
}

