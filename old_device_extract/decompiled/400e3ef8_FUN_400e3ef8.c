// Function : FUN_400e3ef8
// Address  : 0x400e3ef8
// Size     : 1833 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_400e3ef8(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *******pppppppuVar7;
  int *piVar8;
  int iVar9;
  undefined1 auStack_74 [8];
  undefined4 ******local_6c [3];
  byte bStack_5d;
  undefined4 ******local_5c [3];
  byte bStack_4d;
  undefined1 auStack_4c [16];
  undefined4 *****pppppuStack_3c;
  undefined1 auStack_38 [16];
  undefined4 uStack_28;
  int *piStack_24;
  
  memw();
  memw();
  piStack_24 = _DAT_3ffc5708;
  piVar3 = (int *)FUN_400d4330(param_3 + 0x18,"Missing params");
  iVar4 = FUN_400e0528();
  if (iVar4 == 0) {
    FUN_400f0be8(&pppppuStack_3c,"mmand: ");
    *param_1 = 1;
    FUN_400f0d4c(param_1 + 1,&pppppuStack_3c);
  }
  else {
    if ((piVar3 != (int *)0x0) && ((*(byte *)(piVar3 + 2) & 0x20) != 0)) {
      iVar4 = *piVar3;
      iVar9 = 0;
      while (iVar4 != 0) {
        iVar4 = (*(code *)&LAB_40183a9a_2)(iVar4);
        iVar9 = iVar9 + 1;
      }
      piVar8 = (int *)0x0;
      if (iVar9 != 0) goto LAB_400e3fa4;
    }
    FUN_400f0be8(&pppppuStack_3c,"s field");
    *param_1 = 1;
    FUN_400f0d4c(param_1 + 1,&pppppuStack_3c);
  }
  param_1[5] = 0;
  FUN_400f0a50(&pppppuStack_3c);
  do {
    piVar8 = piStack_24;
    piVar3 = _DAT_3ffc5708;
    memw();
    memw();
    if (piStack_24 == _DAT_3ffc5708) {
      return;
    }
    func_0x40082ecc();
LAB_400e3fa4:
    FUN_401845e4(auStack_74);
    iVar4 = FUN_400ec7a4(auStack_74," in SSL config",piVar8,piVar8);
    if (iVar4 == 0) {
      FUN_400f0be8(&pppppuStack_3c,"rovided");
      *param_1 = 1;
      FUN_400f0d4c(param_1 + 1,&pppppuStack_3c);
      param_1[5] = 0;
      pppppppuVar7 = (undefined4 *******)&pppppuStack_3c;
    }
    else {
      FUN_400f0be8(local_6c,&DAT_3f42161d);
      iVar9 = 0;
      for (iVar4 = *piVar3; iVar4 != 0; iVar4 = (*(code *)&LAB_40183a9a_2)(iVar4)) {
        FUN_400f0be8(local_5c,*(undefined4 *)(iVar4 + 0xc));
        iVar5 = FUN_400f11c0(local_5c,"IVE");
        if (iVar5 == 0) {
          iVar5 = FUN_400f11c0(local_5c,"nn_mode");
          if ((((iVar5 == 0) && (iVar5 = FUN_400f11c0(local_5c,"uration"), iVar5 == 0)) &&
              (iVar5 = FUN_400f11c0(local_5c,"uration"), iVar5 == 0)) &&
             (iVar5 = FUN_400f11c0(local_5c,"efaults"), iVar5 == 0)) {
            iVar5 = FUN_400f11c0(local_5c,"fi_ssid");
            if (iVar5 == 0) {
              iVar5 = FUN_400f11c0(local_5c,"already activated");
              if (((iVar5 == 0) && (iVar5 = FUN_400f11c0(local_5c,"tt_port"), iVar5 == 0)) &&
                 ((iVar5 = FUN_400f11c0(local_5c,"trl_pin"), iVar5 == 0 &&
                  ((iVar5 = FUN_400f11c0(local_5c,"low_ext"), iVar5 == 0 &&
                   (iVar5 = FUN_400f11c0(local_5c,"_credit"), iVar5 == 0)))))) {
                iVar5 = FUN_400f11c0(local_5c,"_broker");
                if ((iVar5 != 0) ||
                   ((iVar5 = FUN_400f11c0(local_5c,"qtt_tls"), iVar5 != 0 ||
                    (iVar5 = FUN_400f11c0(local_5c,"epalive"), iVar5 != 0)))) goto LAB_400e4026;
                iVar5 = FUN_400f11c0(local_5c,"ver_url");
                if (((iVar5 != 0) ||
                    (((iVar5 = FUN_400f11c0(local_5c,"ay_mode"), iVar5 != 0 ||
                      (iVar5 = FUN_400f11c0(local_5c,"ev_type"), iVar5 != 0)) ||
                     (iVar5 = FUN_400f11c0(local_5c,"ty: %s\n"), iVar5 != 0)))) ||
                   (iVar5 = FUN_400f11c0(local_5c,"lse_dur"), iVar5 != 0)) goto LAB_400e42ce;
                iVar5 = FUN_400f11c0(local_5c,"lse_low");
                if (((iVar5 == 0) && (iVar5 = FUN_400f11c0(local_5c,"edit_pp"), iVar5 == 0)) &&
                   (iVar5 = FUN_400f11c0(local_5c,"se_high"), iVar5 == 0)) {
                  iVar5 = FUN_400f11c0(local_5c,"pe: %d\n");
                  if (iVar5 == 0) {
                    iVar5 = FUN_400f11c0(local_5c,"igured!");
                    if (iVar5 != 0) goto LAB_400e4282;
                    iVar5 = FUN_400f11c0(local_5c,"n_pulse");
                    if (iVar5 != 0) goto LAB_400e4238;
                    iVar5 = FUN_400f11c0(local_5c,"_act_en");
                    if (iVar5 != 0) {
LAB_400e42ce:
                      iVar5 = FUN_400e08b0(iVar4);
                      if (iVar5 != 0) {
                        pppppppuVar7 = local_5c;
                        if ((bStack_4d & 0x80) == 0) {
                          pppppppuVar7 = (undefined4 *******)local_5c[0];
                        }
                        uVar1 = FUN_400e08fc(iVar4);
                        iVar5 = FUN_400ec968(auStack_74,pppppppuVar7,uVar1);
                        goto LAB_400e4124;
                      }
                      goto LAB_400e43f8;
                    }
                    iVar5 = FUN_400f11c0(local_5c,"act_win");
                    if (iVar5 != 0) goto LAB_400e430b;
                    iVar5 = FUN_400f11c0(local_5c,"act_pin");
                    if (((iVar5 != 0) || (iVar5 = FUN_400f11c0(local_5c,"t_estop"), iVar5 != 0)) ||
                       ((iVar5 = FUN_400f11c0(local_5c,"ct_alow"), iVar5 != 0 ||
                        ((iVar5 = FUN_400f11c0(local_5c,"f_grace"), iVar5 != 0 ||
                         (iVar5 = FUN_400f11c0(local_5c,"enf_ack"), iVar5 != 0))))))
                    goto LAB_400e4282;
                    iVar5 = FUN_400f11c0(local_5c,"nf_cool");
                    if ((iVar5 != 0) ||
                       (((iVar5 = FUN_400f11c0(local_5c,"max=%d\n"), iVar5 != 0 ||
                         (iVar5 = FUN_400f11c0(local_5c,"_mdb_rx"), iVar5 != 0)) ||
                        (iVar5 = FUN_400f11c0(local_5c,"mdb_prx"), iVar5 != 0)))) goto LAB_400e42ce;
                    iVar5 = FUN_400f11c0(local_5c,"db_addr");
                    if (iVar5 != 0) goto LAB_400e4282;
                    FUN_400f0be8(auStack_4c,"ce_size");
                    iVar5 = FUN_400f12d8(local_5c,auStack_4c);
                    FUN_400f0a50(auStack_4c);
                    if ((iVar5 != 0) &&
                       ((iVar5 = FUN_400e0438(local_5c,"_price_"), iVar5 != 0 ||
                        (iVar5 = FUN_400e0438(local_5c,"ev_pulse_dur"), iVar5 != 0)))) {
                      iVar5 = FUN_400e0438(local_5c,"_price_");
                      if ((iVar5 != 0) &&
                         ((iVar5 = (*(code *)&LAB_401841c2_2)(iVar4), iVar5 != 0 ||
                          (iVar5 = (*(code *)&LAB_401841d7_1)(iVar4), iVar5 != 0))))
                      goto LAB_400e424f;
                      iVar5 = FUN_400e0438(local_5c,"ev_pulse_dur");
                      if ((iVar5 != 0) && (iVar5 = FUN_400e08b0(iVar4), iVar5 != 0)) {
                        pppppppuVar7 = local_5c;
                        if ((bStack_4d & 0x80) == 0) {
                          pppppppuVar7 = (undefined4 *******)local_5c[0];
                        }
                        uVar6 = FUN_400e08fc(iVar4);
                        iVar5 = FUN_400ecbf0(auStack_74,pppppppuVar7,uVar6);
                        goto LAB_400e4124;
                      }
                    }
                  }
                  else {
LAB_400e4238:
                    iVar5 = (*(code *)&LAB_401841c2_2)(iVar4);
                    if ((iVar5 != 0) || (iVar5 = (*(code *)&LAB_401841d7_1)(iVar4), iVar5 != 0)) {
LAB_400e424f:
                      pppppppuVar7 = local_5c;
                      if ((bStack_4d & 0x80) == 0) {
                        pppppppuVar7 = (undefined4 *******)local_5c[0];
                      }
                      uVar6 = FUN_400e09a4(iVar4);
                      iVar5 = FUN_400ecec4(auStack_74,pppppppuVar7,uVar6);
                      goto LAB_400e4124;
                    }
                  }
                }
                else {
LAB_400e4282:
                  iVar5 = FUN_400e08b0(iVar4);
                  if (iVar5 != 0) {
                    pppppppuVar7 = local_5c;
                    if ((bStack_4d & 0x80) == 0) {
                      pppppppuVar7 = (undefined4 *******)local_5c[0];
                    }
                    uVar2 = FUN_400e08fc(iVar4);
                    iVar5 = FUN_400eca40(auStack_74,pppppppuVar7,uVar2);
                    goto LAB_400e4124;
                  }
                }
              }
              else {
LAB_400e430b:
                if ((*(byte *)(iVar4 + 8) & 0x7f) == 6) {
                  pppppppuVar7 = local_5c;
                  if ((bStack_4d & 0x80) == 0) {
                    pppppppuVar7 = (undefined4 *******)local_5c[0];
                  }
                  uVar6 = FUN_400e0528(iVar4);
                  iVar5 = FUN_400eccc8(auStack_74,pppppppuVar7,uVar6);
                  goto LAB_400e4124;
                }
              }
            }
            else {
              iVar5 = (*(code *)&LAB_4018416e_2)(iVar4);
              if (iVar5 != 0) {
                pppppppuVar7 = local_5c;
                if ((bStack_4d & 0x80) == 0) {
                  pppppppuVar7 = (undefined4 *******)local_5c[0];
                }
                FUN_400e3ea8(&pppppuStack_3c,iVar4);
                iVar5 = FUN_400ecdc4(auStack_74,pppppppuVar7,&pppppuStack_3c);
                goto LAB_400e4110;
              }
            }
          }
          else {
            iVar5 = (*(code *)&LAB_4018416e_2)(iVar4);
            if (iVar5 != 0) {
              pppppppuVar7 = local_5c;
              if ((bStack_4d & 0x80) == 0) {
                pppppppuVar7 = (undefined4 *******)local_5c[0];
              }
              FUN_400e3ea8(&pppppuStack_3c,iVar4);
              iVar5 = FUN_400ecdc4(auStack_74,pppppppuVar7,&pppppuStack_3c);
LAB_400e4110:
              FUN_400f0a50(&pppppuStack_3c);
              goto LAB_400e4124;
            }
          }
        }
        else {
LAB_400e4026:
          iVar5 = FUN_400e08b0(iVar4);
          if (iVar5 != 0) {
            pppppppuVar7 = local_5c;
            if ((bStack_4d & 0x80) == 0) {
              pppppppuVar7 = (undefined4 *******)local_5c[0];
            }
            uVar6 = FUN_400e08fc(iVar4);
            iVar5 = FUN_400ecb18(auStack_74,pppppppuVar7,uVar6);
LAB_400e4124:
            if (iVar5 != 0) {
              iVar9 = iVar9 + 1;
              iVar5 = (*(code *)&LAB_40183a7b_1)(local_6c);
              if (iVar5 != 0) {
                FUN_400f1050(local_6c,"mespace");
              }
              FUN_400f0fa0(local_6c,local_5c);
            }
          }
        }
LAB_400e43f8:
        FUN_400f0a50(local_5c);
      }
      FUN_400ec888(auStack_74);
      if (iVar9 == 0) {
        FUN_400f0be8(&pppppuStack_3c,"pace");
        *param_1 = 1;
        FUN_400f0d4c(param_1 + 1,&pppppuStack_3c);
        param_1[5] = 0;
        FUN_400f0a50(&pppppuStack_3c);
      }
      else {
        pppppppuVar7 = local_6c;
        if ((bStack_5d & 0x80) == 0) {
          pppppppuVar7 = (undefined4 *******)local_6c[0];
        }
        FUN_400f06a4(0x3ffc5490,"applied",iVar9,pppppppuVar7);
        FUN_400f0be8(auStack_4c,"ys: %s\n");
        pppppuStack_3c = (undefined4 ******)0x0;
        FUN_400f0d4c(auStack_38,auStack_4c);
        uStack_28 = 0;
        FUN_400f0a50(auStack_4c);
        FUN_400f0be8(auStack_4c,"ssfully");
        FUN_400e2f28(&pppppuStack_3c,auStack_4c,iVar9);
        FUN_400f0a50(auStack_4c);
        FUN_400f0be8(local_5c,"d_count");
        FUN_400f0d4c(auStack_4c,local_6c);
        FUN_400e15cc(&pppppuStack_3c,local_5c,auStack_4c);
        FUN_400f0a50(auStack_4c);
        FUN_400f0a50(local_5c);
        FUN_400f0be8(auStack_4c,"ed_keys");
        FUN_400e1730(&pppppuStack_3c,auStack_4c,1);
        FUN_400f0a50(auStack_4c);
        FUN_400f0be8(auStack_4c,"heduled");
        FUN_400e2f28(&pppppuStack_3c,auStack_4c,3);
        FUN_400f0a50(auStack_4c);
        if (DAT_3ffc4ac0 == '\0') {
          DAT_3ffc4ac0 = '\x01';
          func_0x40090934(0x400e46e4,"seconds",0x800,0,1,0,0x7fffffff);
        }
        *param_1 = pppppuStack_3c;
        FUN_400f0d04(param_1 + 1,auStack_38);
        param_1[5] = uStack_28;
        uStack_28 = 0;
        FUN_400e0700(&pppppuStack_3c);
      }
      pppppppuVar7 = local_6c;
    }
    FUN_400f0a50(pppppppuVar7);
    FUN_400ec8a0(auStack_74);
  } while( true );
}

