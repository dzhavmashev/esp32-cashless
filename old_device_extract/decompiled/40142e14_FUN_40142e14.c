// Function : FUN_40142e14
// Address  : 0x40142e14
// Size     : 656 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40142e14(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                 uint param_6,undefined4 param_7,uint param_8,int param_9,uint param_10,
                 int *param_11)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uStack_178;
  int iStack_16c;
  undefined4 uStack_168;
  undefined1 auStack_164 [4];
  int iStack_160;
  int iStack_15c;
  undefined1 auStack_158 [16];
  undefined1 auStack_148 [32];
  undefined1 uStack_128;
  undefined1 auStack_127 [259];
  int iStack_24;
  int aiStack_20 [8];
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  iStack_16c = 0;
  if ((param_5 == 0) && (piVar3 = (int *)&DAT_ffffe080, param_6 != 0)) goto LAB_40142e76;
  memw();
  iVar1 = FUN_40132c44(param_3);
  piVar3 = (int *)0xffffe100;
  if (iVar1 == 0) goto LAB_40142e76;
  uStack_178 = *(uint *)(iVar1 + 8);
  uVar6 = param_8;
  iVar4 = iVar1;
  if (param_2 != 0) goto LAB_40142e95;
  do {
    piVar3 = (int *)0xffffff94;
    if (param_10 < uVar6) goto LAB_40142e76;
    do {
      iVar4 = *(int *)(iVar1 + 0x10);
      uStack_168 = 0;
      if (param_6 < 0x81) {
        memw();
        (*(code *)&SUB_4008b530)(auStack_164,0,0xc);
        (*(code *)&SUB_4008b530)(&uStack_128,0,0x102);
        iVar8 = param_1[2] + param_1[1];
        piVar3 = (int *)0xffffe11e;
        if (*param_1 == 0x30) {
          memw();
          iVar2 = FUN_40141738(param_1 + 2,iVar8,&iStack_160);
          if (iVar2 == 0) {
            iStack_15c = param_1[2];
            param_1[2] = iStack_15c + iStack_160;
            memw();
            iVar2 = FUN_4014180c(param_1 + 2,iVar8,&uStack_168);
            if (iVar2 != 0) goto LAB_40142f05;
            piVar3 = (int *)0xffffe11a;
            if (iVar8 != param_1[2]) goto LAB_40142e76;
          }
          else {
LAB_40142f05:
            piVar3 = (int *)(iVar2 + -0x1e80);
            if ((int *)(iVar2 + -0x1e80) != (int *)0x0) goto LAB_40142e76;
          }
          puVar5 = &uStack_128;
          uVar6 = 0;
          while (param_6 != uVar6) {
            puVar7 = (undefined1 *)(param_5 + uVar6);
            uVar6 = uVar6 + 1;
            puVar5[1] = *puVar7;
            memw();
            puVar5 = puVar5 + 2;
            memw();
          }
          param_6 = (param_6 + 1) * 2;
          param_5 = uStack_178 >> 3;
          memw();
          piVar3 = (int *)FUN_40142b24(auStack_148,param_5,&uStack_128,param_6,iStack_15c,iStack_160
                                       ,param_4,1,uStack_168);
          if (piVar3 == (int *)0x0) {
            if (iVar4 != 0) {
              memw();
              piVar3 = (int *)FUN_40142b24(auStack_158,iVar4,&uStack_128,param_6,iStack_15c,
                                           iStack_160,param_4,2,uStack_168);
              if (piVar3 != (int *)0x0) goto LAB_40142e76;
            }
            FUN_40132c84(&uStack_128);
            piVar3 = (int *)FUN_40133068(&uStack_128,iVar1);
            if ((((piVar3 == (int *)0x0) &&
                 (piVar3 = (int *)FUN_40132cb4(&uStack_128,auStack_148,param_5 << 3,param_2),
                 piVar3 == (int *)0x0)) &&
                (piVar3 = (int *)FUN_40132fe8(&uStack_128,0), piVar3 == (int *)0x0)) &&
               (((piVar3 = (int *)FUN_40132cfc(&uStack_128,auStack_158,*(undefined4 *)(iVar1 + 0x10)
                                              ), piVar3 == (int *)0x0 &&
                 (piVar3 = (int *)FUN_40132d3c(&uStack_128), piVar3 == (int *)0x0)) &&
                (piVar3 = (int *)FUN_40132d58(&uStack_128,param_7,param_8,param_9,param_11),
                piVar3 == (int *)0x0)))) {
              iVar1 = FUN_40132f28(&uStack_128,param_9 + *param_11,&iStack_16c);
              piVar3 = (int *)0x0;
              if (iVar1 != 0) {
                piVar3 = (int *)0xffffe200;
              }
              *param_11 = *param_11 + iStack_16c;
            }
            memw();
            FUN_4013ae54(auStack_148,0x20);
            FUN_4013ae54(auStack_158,0x10);
            param_11 = aiStack_20;
            FUN_40132c98(&uStack_128);
          }
        }
      }
      else {
        piVar3 = (int *)&DAT_ffffe080;
      }
LAB_40142e76:
      param_1 = piVar3;
      iVar1 = iStack_24;
      param_2 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      memw();
      iVar4 = (*(code *)&SUB_40082ec4)();
LAB_40142e95:
    } while (param_2 != 1);
    uVar6 = (*(uint *)(iVar4 + 0x18) + param_8) - param_8 % *(uint *)(iVar4 + 0x18);
  } while( true );
}

